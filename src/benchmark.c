/* Benchmark harness for the recursive fast matrix-multiplication kernels.
 *
 * Every kernel is the *same* recursive algorithm as a function of the matrix
 * size, so the interesting questions are (a) how the fast algorithms compare
 * with BLAS and (b) how their measured exponent approaches log_k(rank).
 *
 * Because a single 4x4 level at N = 16384 already needs several GiB, the
 * harness caps its own allocations (--mem-limit) and aborts with a clear
 * message instead of being killed by the OOM killer; see cmat.c.
 *
 * Examples
 *   ./cfmm --list
 *   ./cfmm --all --levels 1 --base 512 --mem-limit 24000
 *   ./cfmm --alg 4x4 --n 8192 --base 128 --check --repeat 3
 */

#include "cmat.h"
#include "matmul.h"

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/resource.h>

#if defined(CFMM_HAVE_3_3)
#include "fmm_3x3.h"
#endif
#if defined(CFMM_HAVE_3_3_6)
#include "fmm_3x3x6.h"
#endif
#if defined(CFMM_HAVE_4_4)
#include "fmm_4x4.h"
#endif
#if defined(CFMM_HAVE_4_4R43)
#include "fmm_4x4r43.h"
#endif
#if defined(CFMM_HAVE_4_4R46)
#include "fmm_4x4r46.h"
#endif
#if defined(CFMM_HAVE_4_4R47)
#include "fmm_4x4r47.h"
#endif
#if defined(CFMM_HAVE_32_32)
#include "fmm_32x32.h"
#endif

typedef int (*fmm_fn)(double_cmat C, double_cmat A, double_cmat B);

typedef struct {
    const char *name;
    fmm_fn fn;
    /* accepted relative error w.r.t. ||C|| (the rank-20 3x3 algorithm is a
     * border-rank approximation, everything else here is exact) */
    double tol;
    /* macro-block split of A/B along the inner dimension, used by --levels */
    int a_rows, a_cols, b_cols;
    unsigned long *fast_calls;
    unsigned long *blas_calls;
    /* rectangular 3x3x6 needs a wider B for a balanced recursion */
    int wide_b;
} alg_entry;

static alg_entry ALGS[] = {
#if defined(CFMM_HAVE_3_3)
    {"3x3", fmm_3x3, 5e-2, 3, 3, 3, &fmm_3x3_fast_calls, &fmm_3x3_blas_calls, 0},
#endif
#if defined(CFMM_HAVE_3_3_6)
    {"3x3x6", fmm_3x3x6, 1e-9, 3, 3, 6, &fmm_3x3x6_fast_calls, &fmm_3x3x6_blas_calls, 1},
#endif
#if defined(CFMM_HAVE_4_4)
    {"4x4", fmm_4x4, 1e-9, 4, 4, 4, &fmm_4x4_fast_calls, &fmm_4x4_blas_calls, 0},
#endif
#if defined(CFMM_HAVE_4_4R43)
    /* rank-43/46/47 approximate 4x4x4 (border-rank style search) */
    {"4x4r43", fmm_4x4r43, 2e-1, 4, 4, 4, &fmm_4x4r43_fast_calls, &fmm_4x4r43_blas_calls, 0},
#endif
#if defined(CFMM_HAVE_4_4R46)
    {"4x4r46", fmm_4x4r46, 2e-1, 4, 4, 4, &fmm_4x4r46_fast_calls, &fmm_4x4r46_blas_calls, 0},
#endif
#if defined(CFMM_HAVE_4_4R47)
    {"4x4r47", fmm_4x4r47, 2e-1, 4, 4, 4, &fmm_4x4r47_fast_calls, &fmm_4x4r47_blas_calls, 0},
#endif
#if defined(CFMM_HAVE_32_32)
    {"32x32", fmm_32x32, 1e-9, 32, 32, 32, &fmm_32x32_fast_calls, &fmm_32x32_blas_calls, 0},
#endif
    {NULL, NULL, 0.0, 0, 0, 0, NULL, NULL, 0},
};

static double now_seconds(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (double)ts.tv_sec + (double)ts.tv_nsec * 1e-9;
}

static double max_rss_bytes(void) {
    struct rusage ru;
    getrusage(RUSAGE_SELF, &ru);
    return (double)ru.ru_maxrss; /* macOS reports bytes */
}

static int int_pow(int base, int exp) {
    int r = 1;
    for (int i = 0; i < exp; i++) {
        r *= base;
    }
    return r;
}

static void fill_random(double_cmat m, unsigned seed) {
    srand(seed);
    for (shape_uint i = 0; i < m.shape[0]; i++) {
        for (shape_uint j = 0; j < m.shape[1]; j++) {
            m.data[i][j] = 2.0 * rand() / RAND_MAX - 1.0;
        }
    }
}

/* Relative to the magnitude of the reference matrix: a per-element relative
 * error is meaningless for the (many) entries that are close to zero. */
static double matrix_error(double_cmat C, double_cmat T, shape_uint *wi, shape_uint *wj) {
    double scale = 0.0, worst = 0.0;
    *wi = *wj = 0;
    for (shape_uint i = 0; i < T.shape[0]; i++)
        for (shape_uint j = 0; j < T.shape[1]; j++) {
            double v = fabs(T.data[i][j]);
            if (v > scale) scale = v;
        }
    if (scale == 0.0) scale = 1.0;
    for (shape_uint i = 0; i < C.shape[0]; i++)
        for (shape_uint j = 0; j < C.shape[1]; j++) {
            double err = fabs(C.data[i][j] - T.data[i][j]) / scale;
            if (err > worst) {
                worst = err;
                *wi = i;
                *wj = j;
            }
        }
    return worst;
}

static int check_result(double_cmat C, double_cmat T, double tol) {
    shape_uint wi, wj;
    double worst = matrix_error(C, T, &wi, &wj);
    if (worst > tol) {
        fprintf(stderr, "  !! verification failed: max rel err %.3e at (%u,%u)\n", worst, wi, wj);
        return -1;
    }
    return 0;
}

static void usage(const char *argv0) {
    printf(
        "usage: %s [options]\n"
        "  --list                 list available kernels\n"
        "  --alg NAME             kernel to run (repeatable, comma separated)\n"
        "  --all                  run every available kernel\n"
        "  --n N                  matrix dimension (square) or M for 3x3x6\n"
        "  --levels L             derive sizes from --base and the block split\n"
        "  --base T               BLAS fallback threshold (fmm_base_block)\n"
        "  --mem-limit MB         cap on allocations made by the matrix helpers\n"
        "  --repeat R             run R times, keep the best (default 1)\n"
        "  --check                verify against BLAS\n"
        "  --blas                 also time BLAS (default when --check)\n"
        "  --threads T            BLAS threads (default: BLAS default)\n"
        "  --tol X                accepted relative error (default: per algorithm)\n"
        "  --seed S               RNG seed (default 1)\n"
        "  --csv FILE             append one CSV row per measurement\n",
        argv0);
}

int main(int argc, char **argv) {
    const char *selected[16];
    int n_selected = 0;
    int run_all = 0, do_check = 0, do_blas = 0;
    int n_given = 0, levels = -1, repeat = 1, threads = -1;
    long mem_limit_mb = 0;
    double tol_override = 0.0;
    unsigned seed = 1;
    const char *csv_path = NULL;

    static struct option long_opts[] = {
        {"list", no_argument, 0, 1},
        {"alg", required_argument, 0, 2},
        {"all", no_argument, 0, 3},
        {"n", required_argument, 0, 4},
        {"levels", required_argument, 0, 5},
        {"base", required_argument, 0, 6},
        {"mem-limit", required_argument, 0, 7},
        {"repeat", required_argument, 0, 8},
        {"check", no_argument, 0, 9},
        {"blas", no_argument, 0, 10},
        {"threads", required_argument, 0, 11},
        {"seed", required_argument, 0, 12},
        {"csv", required_argument, 0, 13},
        {"tol", required_argument, 0, 15},
        {"help", no_argument, 0, 14},
        {0, 0, 0, 0},
    };

    int opt, idx;
    while ((opt = getopt_long(argc, argv, "", long_opts, &idx)) != -1) {
        switch (opt) {
        case 1:
            for (alg_entry *a = ALGS; a->name; a++) printf("%s\n", a->name);
            return 0;
        case 2:
            for (char *tok = strtok(optarg, ","); tok && n_selected < 16; tok = strtok(NULL, ","))
                selected[n_selected++] = tok;
            break;
        case 3: run_all = 1; break;
        case 4: n_given = atoi(optarg); break;
        case 5: levels = atoi(optarg); break;
        case 6: fmm_base_block = atoi(optarg); break;
        case 7: mem_limit_mb = atol(optarg); break;
        case 8: repeat = atoi(optarg); break;
        case 9: do_check = 1; do_blas = 1; break;
        case 10: do_blas = 1; break;
        case 11: threads = atoi(optarg); break;
        case 12: seed = (unsigned)atoi(optarg); break;
        case 13: csv_path = optarg; break;
        case 15: tol_override = atof(optarg); break;
        default: usage(argv[0]); return 0;
        }
    }

    if (mem_limit_mb > 0) {
        cmat_memory_limit = (size_t)mem_limit_mb << 20;
        /* backstop: let our own accounting fire first, but never let the
         * process run away into swap / the OOM killer. */
        struct rlimit rl;
        if (getrlimit(RLIMIT_AS, &rl) == 0) {
            rlim_t hard = cmat_memory_limit + ((rlim_t)8 << 30);
            rl.rlim_cur = (rl.rlim_max == RLIM_INFINITY || hard < rl.rlim_max) ? hard : rl.rlim_max;
            setrlimit(RLIMIT_AS, &rl);
        }
    }
    if (threads > 0) {
        /* Must happen before BLAS is first used; covers Accelerate and OpenBLAS. */
        char buf[16];
        snprintf(buf, sizeof(buf), "%d", threads);
        setenv("VECLIB_MAXIMUM_THREADS", buf, 1);
        setenv("OPENBLAS_NUM_THREADS", buf, 1);
        setenv("OMP_NUM_THREADS", buf, 1);
    }

    if (run_all) {
        n_selected = 0;
        for (alg_entry *a = ALGS; a->name && n_selected < 16; a++) {
            selected[n_selected++] = a->name;
        }
    }
    if (n_selected == 0) {
        usage(argv[0]);
        return 1;
    }

    FILE *csv = NULL;
    if (csv_path) {
        /* header when the file is missing *or* empty */
        int fresh = 0;
        FILE *probe = fopen(csv_path, "r");
        if (probe) {
            fresh = (fgetc(probe) == EOF);
            fclose(probe);
        } else {
            fresh = 1;
        }
        csv = fopen(csv_path, "a");
        if (csv && fresh) {
            fprintf(csv, "alg,M,K,N,base,seconds,gflops,peak_alloc_MB,max_rss_MB,fast_calls,blas_calls,err\n");
        }
    }

    printf("%-8s %8s %8s %6s %10s %9s %8s %8s %10s %10s\n",
           "alg", "M=K", "N", "base", "sec", "GFLOP/s", "peakMB", "rel.err", "fast", "blascalls");

    int worst_status = 0;
    for (int si = 0; si < n_selected; si++) {
        alg_entry *a = NULL;
        for (alg_entry *it = ALGS; it->name; it++) {
            if (strcmp(it->name, selected[si]) == 0) {
                a = it;
                break;
            }
        }
        if (!a) {
            fprintf(stderr, "unknown algorithm %s\n", selected[si]);
            worst_status = 1;
            continue;
        }

        /* work out the problem shape */
        long M, K, N;
        if (n_given > 0) {
            M = n_given;
            K = n_given;
            N = a->wide_b ? (long)n_given * 2 : n_given;
        } else if (levels >= 0) {
            /* Blocks are cubic: the macro-block factor of A/B along the inner
             * dimension shrinks by a_cols per level, and 3x3x6 keeps the output
             * twice as wide so its B blocks stay square too. */
            M = K = (long)fmm_base_block * int_pow(a->a_cols, levels);
            N = a->wide_b ? 2 * M : M;
        } else {
            fprintf(stderr, "please pass either --n or --levels\n");
            return 1;
        }

        size_t bytes_abc = (size_t)M * K + (size_t)K * N + (size_t)M * N;
        printf("# %s: M=%ld K=%ld N=%ld, A/B/C alone need %.2f GiB\n",
               a->name, M, K, N, (double)bytes_abc * 8.0 / 1073741824.0);
        if (cmat_memory_limit && (bytes_abc + (size_t)M * N) * 8 > cmat_memory_limit) {
            printf("# skipping %s: does not fit in the %ld MiB limit\n", a->name, mem_limit_mb);
            continue;
        }

        double_cmat A, B, C, T;
        memset(&T, 0, sizeof(T));
        create_double_matrix(pairuint{(shape_uint)M, (shape_uint)K}, &A);
        create_double_matrix(pairuint{(shape_uint)K, (shape_uint)N}, &B);
        create_double_matrix(pairuint{(shape_uint)M, (shape_uint)N}, &C);
        fill_random(A, seed);
        fill_random(B, seed + 1);

        if (do_check) {
            create_double_matrix(pairuint{(shape_uint)M, (shape_uint)N}, &T);
            matmul_double_blas(T, A, B);
        }

        cmat_reset_peak();
        double best = 1e300;
        for (int r = 0; r < repeat; r++) {
            for (shape_uint i = 0; i < C.shape[0]; i++)
                memset(C.data[i], 0, C.shape[1] * sizeof(double));
            *a->fast_calls = 0;
            *a->blas_calls = 0;
            double t0 = now_seconds();
            a->fn(C, A, B);
            double t1 = now_seconds();
            if (t1 - t0 < best) best = t1 - t0;
        }
        size_t peak = cmat_peak_bytes;
        double gflops = 2.0 * (double)M * K * N / best / 1e9;

        double err = -1.0;
        int status = 0;
        if (do_check) {
            double tol = tol_override > 0 ? tol_override : a->tol;
            shape_uint wi, wj;
            err = matrix_error(C, T, &wi, &wj);
            status = (err > tol) ? -1 : 0;
            if (status) {
                fprintf(stderr, "  !! %s verification failed: rel err %.3e at (%u,%u), tol %.1e\n",
                        a->name, err, wi, wj, tol);
                worst_status = 1;
            }
        }

        printf("%-8s %8ld %8ld %6d %10.3f %9.2f %8.1f %8.1e %10lu %10lu%s\n",
               a->name, M, N, fmm_base_block, best, gflops,
               (double)peak / 1048576.0, err, *a->fast_calls, *a->blas_calls,
               status ? "  FAILED" : "");

        if (csv) {
            fprintf(csv, "%s,%ld,%ld,%ld,%d,%.6f,%.3f,%.1f,%.1f,%lu,%lu,%.3e\n",
                    a->name, M, K, N, fmm_base_block, best, gflops,
                    (double)peak / 1048576.0, max_rss_bytes() / 1048576.0,
                    *a->fast_calls, *a->blas_calls, err);
            fflush(csv);
        }

        if (do_blas) {
            double bt = 1e300;
            for (int r = 0; r < repeat; r++) {
                for (shape_uint i = 0; i < C.shape[0]; i++)
                    memset(C.data[i], 0, C.shape[1] * sizeof(double));
                double t0 = now_seconds();
                matmul_double_blas(C, A, B);
                double t1 = now_seconds();
                if (t1 - t0 < bt) bt = t1 - t0;
            }
            double bg = 2.0 * (double)M * K * N / bt / 1e9;
            printf("%-8s %8ld %8ld %6d %10.3f %9.2f %8.1f %8s %10s %10s\n",
                   "blas", M, N, fmm_base_block, bt, bg,
                   max_rss_bytes() / 1048576.0, "-", "-", "-");
            if (csv) {
                fprintf(csv, "blas,%ld,%ld,%ld,%d,%.6f,%.3f,%.1f,%.1f,0,0,%.3e\n",
                        M, K, N, fmm_base_block, bt, bg,
                        max_rss_bytes() / 1048576.0, max_rss_bytes() / 1048576.0, 0.0);
                fflush(csv);
            }
        }

        free_double_matrix(A);
        free_double_matrix(B);
        free_double_matrix(C);
        if (do_check) free_double_matrix(T);
    }

    if (csv) fclose(csv);
    return worst_status;
}
