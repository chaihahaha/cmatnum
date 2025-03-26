#include "cmat.h"
#include "fmm_3x3.h"

int fmm_3x3(double_cmat C, double_cmat A, double_cmat B) {
    shape_uint height = A.shape[0];
    shape_uint width = A.shape[1];
    if (height <= 10000 || width <= 10000 || !(height % 3 == width % 3 && height % 3 == 0 && height / 3 == width / 3)) {
        cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                    C.shape[0], C.shape[1], A.shape[1],
                    1.0, A.data[0], A.arena_shape[1],
                    B.data[0], B.arena_shape[1],
                    0.0, C.data[0], C.arena_shape[1]);
        return 0;
    }
    shape_uint N = height;
    shape_uint BL = N/3;
    shape_uint NS = BL*BL;
    double_cmat m;
    double_cmat S;
    double_cmat T;
    create_double_matrix(pairuint {BL, BL}, &m);
    create_double_matrix(pairuint {BL, BL}, &S);
    create_double_matrix(pairuint {BL, BL}, &T);
    double_cmat A_x_0;
    double_cmat B_x_0;
    double_cmat C_x_0;
    double_cmat A_x_1;
    double_cmat B_x_1;
    double_cmat C_x_1;
    double_cmat A_x_2;
    double_cmat B_x_2;
    double_cmat C_x_2;
    create_slice_double_matrix_contiguous(&A_x_0, A, pairint { 0, N }, pairint { 0*BL, 1*BL });
    create_slice_double_matrix_contiguous(&B_x_0, B, pairint { 0, N }, pairint { 0*BL, 1*BL });
    create_double_matrix(pairuint { N, BL }, &C_x_0);
    create_slice_double_matrix_contiguous(&A_x_1, A, pairint { 0, N }, pairint { 1*BL, 2*BL });
    create_slice_double_matrix_contiguous(&B_x_1, B, pairint { 0, N }, pairint { 1*BL, 2*BL });
    create_double_matrix(pairuint { N, BL }, &C_x_1);
    create_slice_double_matrix_contiguous(&A_x_2, A, pairint { 0, N }, pairint { 2*BL, 3*BL });
    create_slice_double_matrix_contiguous(&B_x_2, B, pairint { 0, N }, pairint { 2*BL, 3*BL });
    create_double_matrix(pairuint { N, BL }, &C_x_2);
    double_cmat A_0_0 = slice_double_matrix(A_x_0, pairint {0*BL, 1*BL}, pairint {0, BL});
    double_cmat B_0_0 = slice_double_matrix(B_x_0, pairint {0*BL, 1*BL}, pairint {0, BL});
    double_cmat C_0_0 = slice_double_matrix(C_x_0, pairint {0*BL, 1*BL}, pairint {0, BL});
    double_cmat A_0_1 = slice_double_matrix(A_x_1, pairint {0*BL, 1*BL}, pairint {0, BL});
    double_cmat B_0_1 = slice_double_matrix(B_x_1, pairint {0*BL, 1*BL}, pairint {0, BL});
    double_cmat C_0_1 = slice_double_matrix(C_x_1, pairint {0*BL, 1*BL}, pairint {0, BL});
    double_cmat A_0_2 = slice_double_matrix(A_x_2, pairint {0*BL, 1*BL}, pairint {0, BL});
    double_cmat B_0_2 = slice_double_matrix(B_x_2, pairint {0*BL, 1*BL}, pairint {0, BL});
    double_cmat C_0_2 = slice_double_matrix(C_x_2, pairint {0*BL, 1*BL}, pairint {0, BL});
    double_cmat A_1_0 = slice_double_matrix(A_x_0, pairint {1*BL, 2*BL}, pairint {0, BL});
    double_cmat B_1_0 = slice_double_matrix(B_x_0, pairint {1*BL, 2*BL}, pairint {0, BL});
    double_cmat C_1_0 = slice_double_matrix(C_x_0, pairint {1*BL, 2*BL}, pairint {0, BL});
    double_cmat A_1_1 = slice_double_matrix(A_x_1, pairint {1*BL, 2*BL}, pairint {0, BL});
    double_cmat B_1_1 = slice_double_matrix(B_x_1, pairint {1*BL, 2*BL}, pairint {0, BL});
    double_cmat C_1_1 = slice_double_matrix(C_x_1, pairint {1*BL, 2*BL}, pairint {0, BL});
    double_cmat A_1_2 = slice_double_matrix(A_x_2, pairint {1*BL, 2*BL}, pairint {0, BL});
    double_cmat B_1_2 = slice_double_matrix(B_x_2, pairint {1*BL, 2*BL}, pairint {0, BL});
    double_cmat C_1_2 = slice_double_matrix(C_x_2, pairint {1*BL, 2*BL}, pairint {0, BL});
    double_cmat A_2_0 = slice_double_matrix(A_x_0, pairint {2*BL, 3*BL}, pairint {0, BL});
    double_cmat B_2_0 = slice_double_matrix(B_x_0, pairint {2*BL, 3*BL}, pairint {0, BL});
    double_cmat C_2_0 = slice_double_matrix(C_x_0, pairint {2*BL, 3*BL}, pairint {0, BL});
    double_cmat A_2_1 = slice_double_matrix(A_x_1, pairint {2*BL, 3*BL}, pairint {0, BL});
    double_cmat B_2_1 = slice_double_matrix(B_x_1, pairint {2*BL, 3*BL}, pairint {0, BL});
    double_cmat C_2_1 = slice_double_matrix(C_x_1, pairint {2*BL, 3*BL}, pairint {0, BL});
    double_cmat A_2_2 = slice_double_matrix(A_x_2, pairint {2*BL, 3*BL}, pairint {0, BL});
    double_cmat B_2_2 = slice_double_matrix(B_x_2, pairint {2*BL, 3*BL}, pairint {0, BL});
    double_cmat C_2_2 = slice_double_matrix(C_x_2, pairint {2*BL, 3*BL}, pairint {0, BL});

    cblas_daxpy(NS, 128, A_2_0.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 16384, A_2_2.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, -1.0/2097152.0, A_0_2.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 1.0/128.0, A_0_0.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 1, B_0_0.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 128, B_1_0.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 16384, B_2_0.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 1.0/128.0, B_0_1.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 1.0/1048576.0, B_2_2.data[0], 1, T.data[0], 1);
    fmm_3x3(m, S, T);
    cblas_daxpy(NS, 16384, &m.data[0][0], 1, &C_0_1.data[0][0], 1);
    cblas_daxpy(NS, -1.0/16384.0, &m.data[0][0], 1, &C_1_0.data[0][0], 1);
    cblas_daxpy(NS, 1.0/268435456.0, &m.data[0][0], 1, &C_2_0.data[0][0], 1);
    for(shape_uint arenai=0; arenai<NS; arenai++) S.arena[arenai] = 0;
    for(shape_uint arenai=0; arenai<NS; arenai++) T.arena[arenai] = 0;

    cblas_daxpy(NS, -128, A_1_1.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 16384, A_1_0.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, -1.0/128.0, A_2_2.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 1.0/2097152.0, A_0_2.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 128, B_2_2.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 1.0/2097152.0, B_1_2.data[0], 1, T.data[0], 1);
    fmm_3x3(m, S, T);
    cblas_daxpy(NS, -1.0/128.0, &m.data[0][0], 1, &C_0_0.data[0][0], 1);
    cblas_daxpy(NS, 16384, &m.data[0][0], 1, &C_0_2.data[0][0], 1);
    cblas_daxpy(NS, -1.0/128.0, &m.data[0][0], 1, &C_1_0.data[0][0], 1);
    cblas_daxpy(NS, 1, &m.data[0][0], 1, &C_1_1.data[0][0], 1);
    cblas_daxpy(NS, 1.0/128.0, &m.data[0][0], 1, &C_1_2.data[0][0], 1);
    cblas_daxpy(NS, -1, &m.data[0][0], 1, &C_2_2.data[0][0], 1);
    for(shape_uint arenai=0; arenai<NS; arenai++) S.arena[arenai] = 0;
    for(shape_uint arenai=0; arenai<NS; arenai++) T.arena[arenai] = 0;

    cblas_daxpy(NS, 1, A_1_1.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, -16384, A_2_1.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, -128, A_1_0.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 1, B_1_1.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 128, B_1_0.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, -1.0/16384.0, B_1_2.data[0], 1, T.data[0], 1);
    fmm_3x3(m, S, T);
    cblas_daxpy(NS, 1.0/128.0, &m.data[0][0], 1, &C_0_0.data[0][0], 1);
    cblas_daxpy(NS, -16384, &m.data[0][0], 1, &C_0_2.data[0][0], 1);
    cblas_daxpy(NS, 2097151.0/268435456.0, &m.data[0][0], 1, &C_1_0.data[0][0], 1);
    cblas_daxpy(NS, 1, &m.data[0][0], 1, &C_2_2.data[0][0], 1);
    for(shape_uint arenai=0; arenai<NS; arenai++) S.arena[arenai] = 0;
    for(shape_uint arenai=0; arenai<NS; arenai++) T.arena[arenai] = 0;

    cblas_daxpy(NS, -1, A_0_0.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, -16384, A_2_0.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 128, A_2_1.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 1.0/128.0, A_0_1.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 1, B_1_0.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 128, B_2_0.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 1.0/128.0, B_0_0.data[0], 1, T.data[0], 1);
    fmm_3x3(m, S, T);
    cblas_daxpy(NS, -128, &m.data[0][0], 1, &C_0_0.data[0][0], 1);
    cblas_daxpy(NS, 16384, &m.data[0][0], 1, &C_0_1.data[0][0], 1);
    cblas_daxpy(NS, 1.0/268435456.0, &m.data[0][0], 1, &C_2_0.data[0][0], 1);
    for(shape_uint arenai=0; arenai<NS; arenai++) S.arena[arenai] = 0;
    for(shape_uint arenai=0; arenai<NS; arenai++) T.arena[arenai] = 0;

    cblas_daxpy(NS, 16384, A_1_0.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 16384, A_2_2.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, -1.0/2097152.0, A_0_2.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 1, B_0_0.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 128, B_1_0.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 128, B_2_1.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 16384, B_2_0.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 1.0/128.0, B_0_1.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 1.0/2097152.0, B_2_2.data[0], 1, T.data[0], 1);
    fmm_3x3(m, S, T);
    cblas_daxpy(NS, -16384, &m.data[0][0], 1, &C_0_1.data[0][0], 1);
    cblas_daxpy(NS, 1.0/16384.0, &m.data[0][0], 1, &C_1_0.data[0][0], 1);
    for(shape_uint arenai=0; arenai<NS; arenai++) S.arena[arenai] = 0;
    for(shape_uint arenai=0; arenai<NS; arenai++) T.arena[arenai] = 0;

    cblas_daxpy(NS, -128, A_2_1.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 16384, A_2_0.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 16384, B_1_0.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 1.0/16384.0, B_0_2.data[0], 1, T.data[0], 1);
    fmm_3x3(m, S, T);
    cblas_daxpy(NS, 1, &m.data[0][0], 1, &C_0_0.data[0][0], 1);
    cblas_daxpy(NS, -1, &m.data[0][0], 1, &C_0_1.data[0][0], 1);
    cblas_daxpy(NS, -16384, &m.data[0][0], 1, &C_0_2.data[0][0], 1);
    cblas_daxpy(NS, -129.0/2097152.0, &m.data[0][0], 1, &C_2_0.data[0][0], 1);
    cblas_daxpy(NS, 1.0/16384.0, &m.data[0][0], 1, &C_2_1.data[0][0], 1);
    cblas_daxpy(NS, 1, &m.data[0][0], 1, &C_2_2.data[0][0], 1);
    for(shape_uint arenai=0; arenai<NS; arenai++) S.arena[arenai] = 0;
    for(shape_uint arenai=0; arenai<NS; arenai++) T.arena[arenai] = 0;

    cblas_daxpy(NS, -128, A_2_1.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 16384, A_2_0.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, -1.0/8192.0, A_0_1.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 1.0/128.0, A_0_0.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 128, B_1_0.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 1.0/128.0, B_0_0.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 1.0/2097152.0, B_0_2.data[0], 1, T.data[0], 1);
    fmm_3x3(m, S, T);
    cblas_daxpy(NS, -128, &m.data[0][0], 1, &C_0_0.data[0][0], 1);
    cblas_daxpy(NS, 1.0/128.0, &m.data[0][0], 1, &C_2_0.data[0][0], 1);
    for(shape_uint arenai=0; arenai<NS; arenai++) S.arena[arenai] = 0;
    for(shape_uint arenai=0; arenai<NS; arenai++) T.arena[arenai] = 0;

    cblas_daxpy(NS, 1, A_1_2.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, -16384, A_1_0.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 128, A_2_0.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, -1.0/2097152.0, A_0_2.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 1.0/128.0, A_0_0.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 16384, B_2_0.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 1.0/128.0, B_0_2.data[0], 1, T.data[0], 1);
    fmm_3x3(m, S, T);
    cblas_daxpy(NS, 16384, &m.data[0][0], 1, &C_0_2.data[0][0], 1);
    cblas_daxpy(NS, -127.0/16384.0, &m.data[0][0], 1, &C_1_0.data[0][0], 1);
    for(shape_uint arenai=0; arenai<NS; arenai++) S.arena[arenai] = 0;
    for(shape_uint arenai=0; arenai<NS; arenai++) T.arena[arenai] = 0;

    cblas_daxpy(NS, -16384, A_1_0.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 128, A_1_1.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 128, B_2_2.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 1.0/128.0, B_1_1.data[0], 1, T.data[0], 1);
    fmm_3x3(m, S, T);
    cblas_daxpy(NS, -1.0/128.0, &m.data[0][0], 1, &C_0_0.data[0][0], 1);
    cblas_daxpy(NS, 16384, &m.data[0][0], 1, &C_0_2.data[0][0], 1);
    cblas_daxpy(NS, -1.0/128.0, &m.data[0][0], 1, &C_1_0.data[0][0], 1);
    cblas_daxpy(NS, 2097151.0/2097152.0, &m.data[0][0], 1, &C_1_1.data[0][0], 1);
    cblas_daxpy(NS, -1, &m.data[0][0], 1, &C_2_2.data[0][0], 1);
    for(shape_uint arenai=0; arenai<NS; arenai++) S.arena[arenai] = 0;
    for(shape_uint arenai=0; arenai<NS; arenai++) T.arena[arenai] = 0;

    cblas_daxpy(NS, 16384, A_2_1.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 1, B_1_1.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 128, B_1_0.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 1.0/2097152.0, B_0_2.data[0], 1, T.data[0], 1);
    fmm_3x3(m, S, T);
    cblas_daxpy(NS, 1.0/128.0, &m.data[0][0], 1, &C_0_0.data[0][0], 1);
    cblas_daxpy(NS, -1, &m.data[0][0], 1, &C_0_1.data[0][0], 1);
    cblas_daxpy(NS, -16384, &m.data[0][0], 1, &C_0_2.data[0][0], 1);
    cblas_daxpy(NS, 1.0/128.0, &m.data[0][0], 1, &C_1_0.data[0][0], 1);
    cblas_daxpy(NS, 1.0/16384.0, &m.data[0][0], 1, &C_2_1.data[0][0], 1);
    cblas_daxpy(NS, 1, &m.data[0][0], 1, &C_2_2.data[0][0], 1);
    for(shape_uint arenai=0; arenai<NS; arenai++) S.arena[arenai] = 0;
    for(shape_uint arenai=0; arenai<NS; arenai++) T.arena[arenai] = 0;

    cblas_daxpy(NS, -1, A_1_2.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 16384, A_1_0.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 1, B_1_2.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 1, B_2_1.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 1.0/128.0, B_0_2.data[0], 1, T.data[0], 1);
    fmm_3x3(m, S, T);
    cblas_daxpy(NS, 16384, &m.data[0][0], 1, &C_0_2.data[0][0], 1);
    cblas_daxpy(NS, -1.0/128.0, &m.data[0][0], 1, &C_1_0.data[0][0], 1);
    cblas_daxpy(NS, 1.0/128.0, &m.data[0][0], 1, &C_1_2.data[0][0], 1);
    for(shape_uint arenai=0; arenai<NS; arenai++) S.arena[arenai] = 0;
    for(shape_uint arenai=0; arenai<NS; arenai++) T.arena[arenai] = 0;

    cblas_daxpy(NS, 1, A_1_2.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 1, A_2_1.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, -16384, A_1_0.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 1.0/16384.0, A_0_1.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, -1, B_1_2.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 16384, B_2_0.data[0], 1, T.data[0], 1);
    fmm_3x3(m, S, T);
    cblas_daxpy(NS, -16384, &m.data[0][0], 1, &C_0_2.data[0][0], 1);
    cblas_daxpy(NS, 1.0/128.0, &m.data[0][0], 1, &C_1_0.data[0][0], 1);
    for(shape_uint arenai=0; arenai<NS; arenai++) S.arena[arenai] = 0;
    for(shape_uint arenai=0; arenai<NS; arenai++) T.arena[arenai] = 0;

    cblas_daxpy(NS, -1, A_1_0.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, -128, A_2_1.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 16384, A_2_0.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 1.0/128.0, A_1_1.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 16384, B_1_0.data[0], 1, T.data[0], 1);
    fmm_3x3(m, S, T);
    cblas_daxpy(NS, -1.0/128.0, &m.data[0][0], 1, &C_0_0.data[0][0], 1);
    cblas_daxpy(NS, 16384, &m.data[0][0], 1, &C_0_2.data[0][0], 1);
    cblas_daxpy(NS, 1.0/268435456.0, &m.data[0][0], 1, &C_1_0.data[0][0], 1);
    cblas_daxpy(NS, -1, &m.data[0][0], 1, &C_2_2.data[0][0], 1);
    for(shape_uint arenai=0; arenai<NS; arenai++) S.arena[arenai] = 0;
    for(shape_uint arenai=0; arenai<NS; arenai++) T.arena[arenai] = 0;

    cblas_daxpy(NS, -1, A_0_0.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, -16384, A_2_0.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 128, A_2_1.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 1.0/128.0, A_0_1.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 1.0/16384.0, A_0_2.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 128, B_2_0.data[0], 1, T.data[0], 1);
    fmm_3x3(m, S, T);
    cblas_daxpy(NS, 128, &m.data[0][0], 1, &C_0_0.data[0][0], 1);
    cblas_daxpy(NS, 16384, &m.data[0][0], 1, &C_0_2.data[0][0], 1);
    cblas_daxpy(NS, -1.0/128.0, &m.data[0][0], 1, &C_1_0.data[0][0], 1);
    for(shape_uint arenai=0; arenai<NS; arenai++) S.arena[arenai] = 0;
    for(shape_uint arenai=0; arenai<NS; arenai++) T.arena[arenai] = 0;

    cblas_daxpy(NS, 16384, A_2_2.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 16384, B_2_1.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, -1.0/16384.0, B_2_2.data[0], 1, T.data[0], 1);
    fmm_3x3(m, S, T);
    cblas_daxpy(NS, 128, &m.data[0][0], 1, &C_0_1.data[0][0], 1);
    cblas_daxpy(NS, -16384, &m.data[0][0], 1, &C_0_2.data[0][0], 1);
    cblas_daxpy(NS, -1.0/2097152.0, &m.data[0][0], 1, &C_1_0.data[0][0], 1);
    cblas_daxpy(NS, -1, &m.data[0][0], 1, &C_1_1.data[0][0], 1);
    cblas_daxpy(NS, -1.0/128.0, &m.data[0][0], 1, &C_1_2.data[0][0], 1);
    cblas_daxpy(NS, 1.0/268435456.0, &m.data[0][0], 1, &C_2_1.data[0][0], 1);
    for(shape_uint arenai=0; arenai<NS; arenai++) S.arena[arenai] = 0;
    for(shape_uint arenai=0; arenai<NS; arenai++) T.arena[arenai] = 0;

    cblas_daxpy(NS, -1, A_2_1.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 16384, A_1_0.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, -1.0/16384.0, A_0_1.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 1, B_0_0.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, -1, B_1_1.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 128, B_1_0.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 16384, B_2_0.data[0], 1, T.data[0], 1);
    fmm_3x3(m, S, T);
    cblas_daxpy(NS, 16384, &m.data[0][0], 1, &C_0_1.data[0][0], 1);
    for(shape_uint arenai=0; arenai<NS; arenai++) S.arena[arenai] = 0;
    for(shape_uint arenai=0; arenai<NS; arenai++) T.arena[arenai] = 0;

    cblas_daxpy(NS, 128, A_2_0.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 128, B_1_0.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, -1.0/128.0, B_0_1.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, -1.0/1048576.0, B_2_2.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 1.0/2097152.0, B_0_2.data[0], 1, T.data[0], 1);
    fmm_3x3(m, S, T);
    cblas_daxpy(NS, 16384, &m.data[0][0], 1, &C_0_1.data[0][0], 1);
    cblas_daxpy(NS, 1.0/128.0, &m.data[0][0], 1, &C_2_0.data[0][0], 1);
    cblas_daxpy(NS, -1, &m.data[0][0], 1, &C_2_1.data[0][0], 1);
    for(shape_uint arenai=0; arenai<NS; arenai++) S.arena[arenai] = 0;
    for(shape_uint arenai=0; arenai<NS; arenai++) T.arena[arenai] = 0;

    cblas_daxpy(NS, 1, A_1_1.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, -128, A_1_0.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 1.0/128.0, A_1_2.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 1, B_1_2.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 128, B_2_2.data[0], 1, T.data[0], 1);
    fmm_3x3(m, S, T);
    cblas_daxpy(NS, 1.0/16384.0, &m.data[0][0], 1, &C_1_1.data[0][0], 1);
    cblas_daxpy(NS, 1, &m.data[0][0], 1, &C_1_2.data[0][0], 1);
    for(shape_uint arenai=0; arenai<NS; arenai++) S.arena[arenai] = 0;
    for(shape_uint arenai=0; arenai<NS; arenai++) T.arena[arenai] = 0;

    cblas_daxpy(NS, -1, A_1_0.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 16384, A_2_2.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 1.0/16384.0, A_1_2.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 16384, B_2_1.data[0], 1, T.data[0], 1);
    fmm_3x3(m, S, T);
    cblas_daxpy(NS, 16384, &m.data[0][0], 1, &C_0_2.data[0][0], 1);
    cblas_daxpy(NS, 1, &m.data[0][0], 1, &C_1_1.data[0][0], 1);
    cblas_daxpy(NS, 1.0/128.0, &m.data[0][0], 1, &C_1_2.data[0][0], 1);
    for(shape_uint arenai=0; arenai<NS; arenai++) S.arena[arenai] = 0;
    for(shape_uint arenai=0; arenai<NS; arenai++) T.arena[arenai] = 0;

    cblas_daxpy(NS, 16384, A_1_0.data[0], 1, S.data[0], 1);

    cblas_daxpy(NS, 1, B_1_1.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 128, B_2_1.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 1.0/128.0, B_0_1.data[0], 1, T.data[0], 1);

    cblas_daxpy(NS, 1.0/2097152.0, B_2_2.data[0], 1, T.data[0], 1);
    fmm_3x3(m, S, T);
    cblas_daxpy(NS, 16384, &m.data[0][0], 1, &C_0_1.data[0][0], 1);
    cblas_daxpy(NS, 1.0/128.0, &m.data[0][0], 1, &C_1_1.data[0][0], 1);
    for(shape_uint arenai=0; arenai<NS; arenai++) S.arena[arenai] = 0;
    for(shape_uint arenai=0; arenai<NS; arenai++) T.arena[arenai] = 0;
    assign_double_slice(C, C_x_0, pairint {0, N}, pairint { 0*BL, 1*BL });
    assign_double_slice(C, C_x_1, pairint {0, N}, pairint { 1*BL, 2*BL });
    assign_double_slice(C, C_x_2, pairint {0, N}, pairint { 2*BL, 3*BL });
    free_double_matrix(A_0_0);
    free_double_matrix(B_0_0);
    free_double_matrix(C_0_0);
    free_double_matrix(A_0_1);
    free_double_matrix(B_0_1);
    free_double_matrix(C_0_1);
    free_double_matrix(A_0_2);
    free_double_matrix(B_0_2);
    free_double_matrix(C_0_2);
    free_double_matrix(A_1_0);
    free_double_matrix(B_1_0);
    free_double_matrix(C_1_0);
    free_double_matrix(A_1_1);
    free_double_matrix(B_1_1);
    free_double_matrix(C_1_1);
    free_double_matrix(A_1_2);
    free_double_matrix(B_1_2);
    free_double_matrix(C_1_2);
    free_double_matrix(A_2_0);
    free_double_matrix(B_2_0);
    free_double_matrix(C_2_0);
    free_double_matrix(A_2_1);
    free_double_matrix(B_2_1);
    free_double_matrix(C_2_1);
    free_double_matrix(A_2_2);
    free_double_matrix(B_2_2);
    free_double_matrix(C_2_2);
    free_double_matrix(A_x_0);
    free_double_matrix(B_x_0);
    free_double_matrix(C_x_0);
    free_double_matrix(A_x_1);
    free_double_matrix(B_x_1);
    free_double_matrix(C_x_1);
    free_double_matrix(A_x_2);
    free_double_matrix(B_x_2);
    free_double_matrix(C_x_2);
    free_double_matrix(m);
    free_double_matrix(S);
    free_double_matrix(T);
    return 0;
}
