#!/usr/bin/env bash
# Benchmark driver: sweeps the base-case threshold and the matrix size for each
# available kernel and appends the results to ./results/*.csv
#
#   scripts/run_benchmarks.sh [--quick]
set -u

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
BIN="${ROOT}/build/cfmm"
OUT="${ROOT}/results"
mkdir -p "${OUT}"

QUICK=0
[ "${1:-}" = "--quick" ] && QUICK=1

MEM_LIMIT_MB="${MEM_LIMIT_MB:-30000}"
REPEAT="${REPEAT:-2}"

run() {
    echo "+ cfmm $*" >&2
    "${BIN}" "$@"
}

# ---------------------------------------------------------------------- #
# A. how the multiplication count scales with the recursion depth
#    (this is the algorithmic exponent: rank^levels base-case products)
# ---------------------------------------------------------------------- #
echo "# A: multiplication-count scaling" >&2
rm -f "${OUT}/scaling.csv"
for alg in $("${BIN}" --list | tr '\n' ' '); do
    for L in 1 2 3; do
        case "${alg}" in
            3x3)    base=64 ;;
            3x3x6)  base=48 ;;
            4x4)    base=32 ;;
        esac
        run --alg "${alg}" --levels "${L}" --base "${base}" \
            --repeat 1 --mem-limit "${MEM_LIMIT_MB}" --csv "${OUT}/scaling.csv"
    done
done

# ---------------------------------------------------------------------- #
# B. best base threshold at a fixed (large-ish) size
# ---------------------------------------------------------------------- #
echo "# B: base sweep" >&2
rm -f "${OUT}/base_sweep.csv"
for b in 64 128 256 512 1024 2048 4096; do
    run --alg 4x4 --n 8192 --base "${b}" --repeat "${REPEAT}" \
        --mem-limit "${MEM_LIMIT_MB}" --csv "${OUT}/base_sweep.csv"
done

# ---------------------------------------------------------------------- #
# C. size sweep vs BLAS at the tuned threshold
# ---------------------------------------------------------------------- #
echo "# C: size sweep" >&2
rm -f "${OUT}/size_sweep.csv"
if [ "${QUICK}" = "1" ]; then
    SIZES_3x3="2187 6561"
    SIZES_3x3x6="2304"
    SIZES_4x4="2048 8192"
    SIZES_32x32="8192"
else
    SIZES_3x3="2187 6561 19683"
    SIZES_3x3x6="1152 2304 4608"
    SIZES_4x4="2048 8192 16384"
    SIZES_32x32="8192 16384"
fi

for n in ${SIZES_3x3}; do
    run --alg 3x3 --n "${n}" --base $((n / 3)) --check --blas \
        --repeat "${REPEAT}" --mem-limit "${MEM_LIMIT_MB}" --csv "${OUT}/size_sweep.csv"
done
for n in ${SIZES_3x3x6}; do
    run --alg 3x3x6 --n "${n}" --base $((n / 3)) --check --blas \
        --repeat "${REPEAT}" --mem-limit "${MEM_LIMIT_MB}" --csv "${OUT}/size_sweep.csv"
done
for n in ${SIZES_4x4}; do
    run --alg 4x4 --n "${n}" --base $((n / 4)) --check --blas \
        --repeat "${REPEAT}" --mem-limit "${MEM_LIMIT_MB}" --csv "${OUT}/size_sweep.csv"
done
if "${BIN}" --list | grep -qx 32x32; then
    for n in ${SIZES_32x32}; do
        run --alg 32x32 --n "${n}" --base $((n / 32)) --check --blas \
            --repeat "${REPEAT}" --mem-limit "${MEM_LIMIT_MB}" --csv "${OUT}/size_sweep.csv"
    done
fi

echo "results written to ${OUT}" >&2
