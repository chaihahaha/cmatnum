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
    double_cmat m0,m1,m2,m3,m4,m5,m6,m7,m8,m9,m10,m11,m12,m13,m14,m15,m16,m17,m18,m19;
    double_cmat S0,S1,S2,S3,S4,S5,S6,S7,S8,S9,S10,S11,S12,S13,S14,S15,S16,S17,S18,S19;
    double_cmat T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19;
    create_double_matrix(pairuint {BL, BL}, &m0);
    create_double_matrix(pairuint {BL, BL}, &m1);
    create_double_matrix(pairuint {BL, BL}, &m2);
    create_double_matrix(pairuint {BL, BL}, &m3);
    create_double_matrix(pairuint {BL, BL}, &m4);
    create_double_matrix(pairuint {BL, BL}, &m5);
    create_double_matrix(pairuint {BL, BL}, &m6);
    create_double_matrix(pairuint {BL, BL}, &m7);
    create_double_matrix(pairuint {BL, BL}, &m8);
    create_double_matrix(pairuint {BL, BL}, &m9);
    create_double_matrix(pairuint {BL, BL}, &m10);
    create_double_matrix(pairuint {BL, BL}, &m11);
    create_double_matrix(pairuint {BL, BL}, &m12);
    create_double_matrix(pairuint {BL, BL}, &m13);
    create_double_matrix(pairuint {BL, BL}, &m14);
    create_double_matrix(pairuint {BL, BL}, &m15);
    create_double_matrix(pairuint {BL, BL}, &m16);
    create_double_matrix(pairuint {BL, BL}, &m17);
    create_double_matrix(pairuint {BL, BL}, &m18);
    create_double_matrix(pairuint {BL, BL}, &m19);
    create_double_matrix(pairuint {BL, BL}, &S0);
    create_double_matrix(pairuint {BL, BL}, &S1);
    create_double_matrix(pairuint {BL, BL}, &S2);
    create_double_matrix(pairuint {BL, BL}, &S3);
    create_double_matrix(pairuint {BL, BL}, &S4);
    create_double_matrix(pairuint {BL, BL}, &S5);
    create_double_matrix(pairuint {BL, BL}, &S6);
    create_double_matrix(pairuint {BL, BL}, &S7);
    create_double_matrix(pairuint {BL, BL}, &S8);
    create_double_matrix(pairuint {BL, BL}, &S9);
    create_double_matrix(pairuint {BL, BL}, &S10);
    create_double_matrix(pairuint {BL, BL}, &S11);
    create_double_matrix(pairuint {BL, BL}, &S12);
    create_double_matrix(pairuint {BL, BL}, &S13);
    create_double_matrix(pairuint {BL, BL}, &S14);
    create_double_matrix(pairuint {BL, BL}, &S15);
    create_double_matrix(pairuint {BL, BL}, &S16);
    create_double_matrix(pairuint {BL, BL}, &S17);
    create_double_matrix(pairuint {BL, BL}, &S18);
    create_double_matrix(pairuint {BL, BL}, &S19);
    create_double_matrix(pairuint {BL, BL}, &T0);
    create_double_matrix(pairuint {BL, BL}, &T1);
    create_double_matrix(pairuint {BL, BL}, &T2);
    create_double_matrix(pairuint {BL, BL}, &T3);
    create_double_matrix(pairuint {BL, BL}, &T4);
    create_double_matrix(pairuint {BL, BL}, &T5);
    create_double_matrix(pairuint {BL, BL}, &T6);
    create_double_matrix(pairuint {BL, BL}, &T7);
    create_double_matrix(pairuint {BL, BL}, &T8);
    create_double_matrix(pairuint {BL, BL}, &T9);
    create_double_matrix(pairuint {BL, BL}, &T10);
    create_double_matrix(pairuint {BL, BL}, &T11);
    create_double_matrix(pairuint {BL, BL}, &T12);
    create_double_matrix(pairuint {BL, BL}, &T13);
    create_double_matrix(pairuint {BL, BL}, &T14);
    create_double_matrix(pairuint {BL, BL}, &T15);
    create_double_matrix(pairuint {BL, BL}, &T16);
    create_double_matrix(pairuint {BL, BL}, &T17);
    create_double_matrix(pairuint {BL, BL}, &T18);
    create_double_matrix(pairuint {BL, BL}, &T19);
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

    cblas_daxpy(NS, 10.0, A_2_0.data[0], 1, S0.data[0], 1);

    cblas_daxpy(NS, 0.1, A_0_0.data[0], 1, S0.data[0], 1);

    cblas_daxpy(NS, 99.99999999999999, A_2_2.data[0], 1, S0.data[0], 1);

    cblas_daxpy(NS, -0.0010000000000000002, A_0_2.data[0], 1, S0.data[0], 1);

    cblas_daxpy(NS, 0.0010000000000000002, A_0_2.data[0], 1, S1.data[0], 1);

    cblas_daxpy(NS, 99.99999999999999, A_1_0.data[0], 1, S1.data[0], 1);

    cblas_daxpy(NS, -10.0, A_1_1.data[0], 1, S1.data[0], 1);

    cblas_daxpy(NS, -0.1, A_2_2.data[0], 1, S1.data[0], 1);

    cblas_daxpy(NS, 1.0, A_1_1.data[0], 1, S2.data[0], 1);

    cblas_daxpy(NS, -10.0, A_1_0.data[0], 1, S2.data[0], 1);

    cblas_daxpy(NS, -99.99999999999999, A_2_1.data[0], 1, S2.data[0], 1);

    cblas_daxpy(NS, 10.0, A_2_1.data[0], 1, S3.data[0], 1);

    cblas_daxpy(NS, 0.1, A_0_1.data[0], 1, S3.data[0], 1);

    cblas_daxpy(NS, -1.0, A_0_0.data[0], 1, S3.data[0], 1);

    cblas_daxpy(NS, -99.99999999999999, A_2_0.data[0], 1, S3.data[0], 1);

    cblas_daxpy(NS, 99.99999999999999, A_1_0.data[0], 1, S4.data[0], 1);

    cblas_daxpy(NS, 99.99999999999999, A_2_2.data[0], 1, S4.data[0], 1);

    cblas_daxpy(NS, -0.0010000000000000002, A_0_2.data[0], 1, S4.data[0], 1);

    cblas_daxpy(NS, 99.99999999999999, A_2_0.data[0], 1, S5.data[0], 1);

    cblas_daxpy(NS, -10.0, A_2_1.data[0], 1, S5.data[0], 1);

    cblas_daxpy(NS, 0.1, A_0_0.data[0], 1, S6.data[0], 1);

    cblas_daxpy(NS, 99.99999999999999, A_2_0.data[0], 1, S6.data[0], 1);

    cblas_daxpy(NS, -10.0, A_2_1.data[0], 1, S6.data[0], 1);

    cblas_daxpy(NS, -0.020000000000000004, A_0_1.data[0], 1, S6.data[0], 1);

    cblas_daxpy(NS, 1.0, A_1_2.data[0], 1, S7.data[0], 1);

    cblas_daxpy(NS, 10.0, A_2_0.data[0], 1, S7.data[0], 1);

    cblas_daxpy(NS, 0.1, A_0_0.data[0], 1, S7.data[0], 1);

    cblas_daxpy(NS, -0.0010000000000000002, A_0_2.data[0], 1, S7.data[0], 1);

    cblas_daxpy(NS, -99.99999999999999, A_1_0.data[0], 1, S7.data[0], 1);

    cblas_daxpy(NS, 10.0, A_1_1.data[0], 1, S8.data[0], 1);

    cblas_daxpy(NS, -99.99999999999999, A_1_0.data[0], 1, S8.data[0], 1);

    cblas_daxpy(NS, 99.99999999999999, A_2_1.data[0], 1, S9.data[0], 1);

    cblas_daxpy(NS, 99.99999999999999, A_1_0.data[0], 1, S10.data[0], 1);

    cblas_daxpy(NS, -1.0, A_1_2.data[0], 1, S10.data[0], 1);

    cblas_daxpy(NS, 1.0, A_1_2.data[0], 1, S11.data[0], 1);

    cblas_daxpy(NS, 1.0, A_2_1.data[0], 1, S11.data[0], 1);

    cblas_daxpy(NS, 0.010000000000000002, A_0_1.data[0], 1, S11.data[0], 1);

    cblas_daxpy(NS, -99.99999999999999, A_1_0.data[0], 1, S11.data[0], 1);

    cblas_daxpy(NS, 0.1, A_1_1.data[0], 1, S12.data[0], 1);

    cblas_daxpy(NS, 99.99999999999999, A_2_0.data[0], 1, S12.data[0], 1);

    cblas_daxpy(NS, -1.0, A_1_0.data[0], 1, S12.data[0], 1);

    cblas_daxpy(NS, -10.0, A_2_1.data[0], 1, S12.data[0], 1);

    cblas_daxpy(NS, 10.0, A_2_1.data[0], 1, S13.data[0], 1);

    cblas_daxpy(NS, 0.010000000000000002, A_0_2.data[0], 1, S13.data[0], 1);

    cblas_daxpy(NS, 0.1, A_0_1.data[0], 1, S13.data[0], 1);

    cblas_daxpy(NS, -1.0, A_0_0.data[0], 1, S13.data[0], 1);

    cblas_daxpy(NS, -99.99999999999999, A_2_0.data[0], 1, S13.data[0], 1);

    cblas_daxpy(NS, 99.99999999999999, A_2_2.data[0], 1, S14.data[0], 1);

    cblas_daxpy(NS, 99.99999999999999, A_1_0.data[0], 1, S15.data[0], 1);

    cblas_daxpy(NS, -1.0, A_2_1.data[0], 1, S15.data[0], 1);

    cblas_daxpy(NS, -0.010000000000000002, A_0_1.data[0], 1, S15.data[0], 1);

    cblas_daxpy(NS, 10.0, A_2_0.data[0], 1, S16.data[0], 1);

    cblas_daxpy(NS, 1.0, A_1_1.data[0], 1, S17.data[0], 1);

    cblas_daxpy(NS, 0.1, A_1_2.data[0], 1, S17.data[0], 1);

    cblas_daxpy(NS, -10.0, A_1_0.data[0], 1, S17.data[0], 1);

    cblas_daxpy(NS, 0.010000000000000002, A_1_2.data[0], 1, S18.data[0], 1);

    cblas_daxpy(NS, 99.99999999999999, A_2_2.data[0], 1, S18.data[0], 1);

    cblas_daxpy(NS, -1.0, A_1_0.data[0], 1, S18.data[0], 1);

    cblas_daxpy(NS, 99.99999999999999, A_1_0.data[0], 1, S19.data[0], 1);

    cblas_daxpy(NS, 1.0, B_0_0.data[0], 1, T0.data[0], 1);

    cblas_daxpy(NS, 10.0, B_1_0.data[0], 1, T0.data[0], 1);

    cblas_daxpy(NS, 0.1, B_0_1.data[0], 1, T0.data[0], 1);

    cblas_daxpy(NS, 0.0020000000000000005, B_2_2.data[0], 1, T0.data[0], 1);

    cblas_daxpy(NS, 99.99999999999999, B_2_0.data[0], 1, T0.data[0], 1);

    cblas_daxpy(NS, 10.0, B_2_2.data[0], 1, T1.data[0], 1);

    cblas_daxpy(NS, 0.0010000000000000002, B_1_2.data[0], 1, T1.data[0], 1);

    cblas_daxpy(NS, 1.0, B_1_1.data[0], 1, T2.data[0], 1);

    cblas_daxpy(NS, 10.0, B_1_0.data[0], 1, T2.data[0], 1);

    cblas_daxpy(NS, -0.010000000000000002, B_1_2.data[0], 1, T2.data[0], 1);

    cblas_daxpy(NS, 1.0, B_1_0.data[0], 1, T3.data[0], 1);

    cblas_daxpy(NS, 10.0, B_2_0.data[0], 1, T3.data[0], 1);

    cblas_daxpy(NS, 0.1, B_0_0.data[0], 1, T3.data[0], 1);

    cblas_daxpy(NS, 1.0, B_0_0.data[0], 1, T4.data[0], 1);

    cblas_daxpy(NS, 10.0, B_1_0.data[0], 1, T4.data[0], 1);

    cblas_daxpy(NS, 10.0, B_2_1.data[0], 1, T4.data[0], 1);

    cblas_daxpy(NS, 0.1, B_0_1.data[0], 1, T4.data[0], 1);

    cblas_daxpy(NS, 0.0010000000000000002, B_2_2.data[0], 1, T4.data[0], 1);

    cblas_daxpy(NS, 99.99999999999999, B_2_0.data[0], 1, T4.data[0], 1);

    cblas_daxpy(NS, 0.010000000000000002, B_0_2.data[0], 1, T5.data[0], 1);

    cblas_daxpy(NS, 99.99999999999999, B_1_0.data[0], 1, T5.data[0], 1);

    cblas_daxpy(NS, 10.0, B_1_0.data[0], 1, T6.data[0], 1);

    cblas_daxpy(NS, 0.1, B_0_0.data[0], 1, T6.data[0], 1);

    cblas_daxpy(NS, 0.0010000000000000002, B_0_2.data[0], 1, T6.data[0], 1);

    cblas_daxpy(NS, 0.1, B_0_2.data[0], 1, T7.data[0], 1);

    cblas_daxpy(NS, 99.99999999999999, B_2_0.data[0], 1, T7.data[0], 1);

    cblas_daxpy(NS, 10.0, B_2_2.data[0], 1, T8.data[0], 1);

    cblas_daxpy(NS, 0.1, B_1_1.data[0], 1, T8.data[0], 1);

    cblas_daxpy(NS, 1.0, B_1_1.data[0], 1, T9.data[0], 1);

    cblas_daxpy(NS, 10.0, B_1_0.data[0], 1, T9.data[0], 1);

    cblas_daxpy(NS, 0.0010000000000000002, B_0_2.data[0], 1, T9.data[0], 1);

    cblas_daxpy(NS, 1.0, B_1_2.data[0], 1, T10.data[0], 1);

    cblas_daxpy(NS, 1.0, B_2_1.data[0], 1, T10.data[0], 1);

    cblas_daxpy(NS, 0.1, B_0_2.data[0], 1, T10.data[0], 1);

    cblas_daxpy(NS, 99.99999999999999, B_2_0.data[0], 1, T11.data[0], 1);

    cblas_daxpy(NS, -1.0, B_1_2.data[0], 1, T11.data[0], 1);

    cblas_daxpy(NS, 99.99999999999999, B_1_0.data[0], 1, T12.data[0], 1);

    cblas_daxpy(NS, 10.0, B_2_0.data[0], 1, T13.data[0], 1);

    cblas_daxpy(NS, 99.99999999999999, B_2_1.data[0], 1, T14.data[0], 1);

    cblas_daxpy(NS, -0.010000000000000002, B_2_2.data[0], 1, T14.data[0], 1);

    cblas_daxpy(NS, 1.0, B_0_0.data[0], 1, T15.data[0], 1);

    cblas_daxpy(NS, 10.0, B_1_0.data[0], 1, T15.data[0], 1);

    cblas_daxpy(NS, 99.99999999999999, B_2_0.data[0], 1, T15.data[0], 1);

    cblas_daxpy(NS, -1.0, B_1_1.data[0], 1, T15.data[0], 1);

    cblas_daxpy(NS, 10.0, B_1_0.data[0], 1, T16.data[0], 1);

    cblas_daxpy(NS, 0.0010000000000000002, B_0_2.data[0], 1, T16.data[0], 1);

    cblas_daxpy(NS, -0.1, B_0_1.data[0], 1, T16.data[0], 1);

    cblas_daxpy(NS, -0.0020000000000000005, B_2_2.data[0], 1, T16.data[0], 1);

    cblas_daxpy(NS, 1.0, B_1_2.data[0], 1, T17.data[0], 1);

    cblas_daxpy(NS, 10.0, B_2_2.data[0], 1, T17.data[0], 1);

    cblas_daxpy(NS, 99.99999999999999, B_2_1.data[0], 1, T18.data[0], 1);

    cblas_daxpy(NS, 1.0, B_1_1.data[0], 1, T19.data[0], 1);

    cblas_daxpy(NS, 10.0, B_2_1.data[0], 1, T19.data[0], 1);

    cblas_daxpy(NS, 0.1, B_0_1.data[0], 1, T19.data[0], 1);

    cblas_daxpy(NS, 0.0010000000000000002, B_2_2.data[0], 1, T19.data[0], 1);
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                BL, BL, BL,
                1.0, S0.data[0], BL,
                T0.data[0], BL,
                0.0, m0.data[0], BL);
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                BL, BL, BL,
                1.0, S1.data[0], BL,
                T1.data[0], BL,
                0.0, m1.data[0], BL);
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                BL, BL, BL,
                1.0, S2.data[0], BL,
                T2.data[0], BL,
                0.0, m2.data[0], BL);
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                BL, BL, BL,
                1.0, S3.data[0], BL,
                T3.data[0], BL,
                0.0, m3.data[0], BL);
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                BL, BL, BL,
                1.0, S4.data[0], BL,
                T4.data[0], BL,
                0.0, m4.data[0], BL);
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                BL, BL, BL,
                1.0, S5.data[0], BL,
                T5.data[0], BL,
                0.0, m5.data[0], BL);
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                BL, BL, BL,
                1.0, S6.data[0], BL,
                T6.data[0], BL,
                0.0, m6.data[0], BL);
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                BL, BL, BL,
                1.0, S7.data[0], BL,
                T7.data[0], BL,
                0.0, m7.data[0], BL);
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                BL, BL, BL,
                1.0, S8.data[0], BL,
                T8.data[0], BL,
                0.0, m8.data[0], BL);
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                BL, BL, BL,
                1.0, S9.data[0], BL,
                T9.data[0], BL,
                0.0, m9.data[0], BL);
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                BL, BL, BL,
                1.0, S10.data[0], BL,
                T10.data[0], BL,
                0.0, m10.data[0], BL);
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                BL, BL, BL,
                1.0, S11.data[0], BL,
                T11.data[0], BL,
                0.0, m11.data[0], BL);
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                BL, BL, BL,
                1.0, S12.data[0], BL,
                T12.data[0], BL,
                0.0, m12.data[0], BL);
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                BL, BL, BL,
                1.0, S13.data[0], BL,
                T13.data[0], BL,
                0.0, m13.data[0], BL);
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                BL, BL, BL,
                1.0, S14.data[0], BL,
                T14.data[0], BL,
                0.0, m14.data[0], BL);
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                BL, BL, BL,
                1.0, S15.data[0], BL,
                T15.data[0], BL,
                0.0, m15.data[0], BL);
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                BL, BL, BL,
                1.0, S16.data[0], BL,
                T16.data[0], BL,
                0.0, m16.data[0], BL);
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                BL, BL, BL,
                1.0, S17.data[0], BL,
                T17.data[0], BL,
                0.0, m17.data[0], BL);
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                BL, BL, BL,
                1.0, S18.data[0], BL,
                T18.data[0], BL,
                0.0, m18.data[0], BL);
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                BL, BL, BL,
                1.0, S19.data[0], BL,
                T19.data[0], BL,
                0.0, m19.data[0], BL);
    cblas_daxpy(NS, 1.0, &m5.data[0][0], 1, &C_0_0.data[0][0], 1);
    cblas_daxpy(NS, 10.0, &m13.data[0][0], 1, &C_0_0.data[0][0], 1);
    cblas_daxpy(NS, 0.1, &m2.data[0][0], 1, &C_0_0.data[0][0], 1);
    cblas_daxpy(NS, 0.1, &m9.data[0][0], 1, &C_0_0.data[0][0], 1);
    cblas_daxpy(NS, -10.0, &m3.data[0][0], 1, &C_0_0.data[0][0], 1);
    cblas_daxpy(NS, -10.0, &m6.data[0][0], 1, &C_0_0.data[0][0], 1);
    cblas_daxpy(NS, -0.1, &m1.data[0][0], 1, &C_0_0.data[0][0], 1);
    cblas_daxpy(NS, -0.1, &m12.data[0][0], 1, &C_0_0.data[0][0], 1);
    cblas_daxpy(NS, -0.1, &m8.data[0][0], 1, &C_0_0.data[0][0], 1);
    cblas_daxpy(NS, 10.0, &m14.data[0][0], 1, &C_0_1.data[0][0], 1);
    cblas_daxpy(NS, 99.99999999999999, &m0.data[0][0], 1, &C_0_1.data[0][0], 1);
    cblas_daxpy(NS, 99.99999999999999, &m15.data[0][0], 1, &C_0_1.data[0][0], 1);
    cblas_daxpy(NS, 99.99999999999999, &m16.data[0][0], 1, &C_0_1.data[0][0], 1);
    cblas_daxpy(NS, 99.99999999999999, &m19.data[0][0], 1, &C_0_1.data[0][0], 1);
    cblas_daxpy(NS, 99.99999999999999, &m3.data[0][0], 1, &C_0_1.data[0][0], 1);
    cblas_daxpy(NS, -1.0, &m5.data[0][0], 1, &C_0_1.data[0][0], 1);
    cblas_daxpy(NS, -1.0, &m9.data[0][0], 1, &C_0_1.data[0][0], 1);
    cblas_daxpy(NS, -99.99999999999999, &m4.data[0][0], 1, &C_0_1.data[0][0], 1);
    cblas_daxpy(NS, 99.99999999999999, &m1.data[0][0], 1, &C_0_2.data[0][0], 1);
    cblas_daxpy(NS, 99.99999999999999, &m10.data[0][0], 1, &C_0_2.data[0][0], 1);
    cblas_daxpy(NS, 99.99999999999999, &m12.data[0][0], 1, &C_0_2.data[0][0], 1);
    cblas_daxpy(NS, 99.99999999999999, &m13.data[0][0], 1, &C_0_2.data[0][0], 1);
    cblas_daxpy(NS, 99.99999999999999, &m18.data[0][0], 1, &C_0_2.data[0][0], 1);
    cblas_daxpy(NS, 99.99999999999999, &m7.data[0][0], 1, &C_0_2.data[0][0], 1);
    cblas_daxpy(NS, 99.99999999999999, &m8.data[0][0], 1, &C_0_2.data[0][0], 1);
    cblas_daxpy(NS, -99.99999999999999, &m11.data[0][0], 1, &C_0_2.data[0][0], 1);
    cblas_daxpy(NS, -99.99999999999999, &m14.data[0][0], 1, &C_0_2.data[0][0], 1);
    cblas_daxpy(NS, -99.99999999999999, &m2.data[0][0], 1, &C_0_2.data[0][0], 1);
    cblas_daxpy(NS, -99.99999999999999, &m5.data[0][0], 1, &C_0_2.data[0][0], 1);
    cblas_daxpy(NS, -99.99999999999999, &m9.data[0][0], 1, &C_0_2.data[0][0], 1);
    cblas_daxpy(NS, 0.010000000000000002, &m4.data[0][0], 1, &C_1_0.data[0][0], 1);
    cblas_daxpy(NS, 0.1, &m11.data[0][0], 1, &C_1_0.data[0][0], 1);
    cblas_daxpy(NS, 0.1, &m9.data[0][0], 1, &C_1_0.data[0][0], 1);
    cblas_daxpy(NS, 0.00010000000000000002, &m12.data[0][0], 1, &C_1_0.data[0][0], 1);
    cblas_daxpy(NS, 0.0999, &m2.data[0][0], 1, &C_1_0.data[0][0], 1);
    cblas_daxpy(NS, -0.010000000000000002, &m0.data[0][0], 1, &C_1_0.data[0][0], 1);
    cblas_daxpy(NS, -0.09, &m7.data[0][0], 1, &C_1_0.data[0][0], 1);
    cblas_daxpy(NS, -0.1, &m1.data[0][0], 1, &C_1_0.data[0][0], 1);
    cblas_daxpy(NS, -0.1, &m10.data[0][0], 1, &C_1_0.data[0][0], 1);
    cblas_daxpy(NS, -0.1, &m13.data[0][0], 1, &C_1_0.data[0][0], 1);
    cblas_daxpy(NS, -0.1, &m8.data[0][0], 1, &C_1_0.data[0][0], 1);
    cblas_daxpy(NS, -0.0010000000000000002, &m14.data[0][0], 1, &C_1_0.data[0][0], 1);
    cblas_daxpy(NS, 1.0, &m1.data[0][0], 1, &C_1_1.data[0][0], 1);
    cblas_daxpy(NS, 1.0, &m18.data[0][0], 1, &C_1_1.data[0][0], 1);
    cblas_daxpy(NS, 0.010000000000000002, &m17.data[0][0], 1, &C_1_1.data[0][0], 1);
    cblas_daxpy(NS, 0.1, &m19.data[0][0], 1, &C_1_1.data[0][0], 1);
    cblas_daxpy(NS, 0.999, &m8.data[0][0], 1, &C_1_1.data[0][0], 1);
    cblas_daxpy(NS, -1.0, &m14.data[0][0], 1, &C_1_1.data[0][0], 1);
    cblas_daxpy(NS, 1.0, &m17.data[0][0], 1, &C_1_2.data[0][0], 1);
    cblas_daxpy(NS, 0.1, &m1.data[0][0], 1, &C_1_2.data[0][0], 1);
    cblas_daxpy(NS, 0.1, &m10.data[0][0], 1, &C_1_2.data[0][0], 1);
    cblas_daxpy(NS, 0.1, &m18.data[0][0], 1, &C_1_2.data[0][0], 1);
    cblas_daxpy(NS, -0.1, &m14.data[0][0], 1, &C_1_2.data[0][0], 1);
    cblas_daxpy(NS, 0.1, &m16.data[0][0], 1, &C_2_0.data[0][0], 1);
    cblas_daxpy(NS, 0.1, &m6.data[0][0], 1, &C_2_0.data[0][0], 1);
    cblas_daxpy(NS, 0.00010000000000000002, &m0.data[0][0], 1, &C_2_0.data[0][0], 1);
    cblas_daxpy(NS, 0.00010000000000000002, &m3.data[0][0], 1, &C_2_0.data[0][0], 1);
    cblas_daxpy(NS, -0.011000000000000003, &m5.data[0][0], 1, &C_2_0.data[0][0], 1);
    cblas_daxpy(NS, 0.010000000000000002, &m5.data[0][0], 1, &C_2_1.data[0][0], 1);
    cblas_daxpy(NS, 0.010000000000000002, &m9.data[0][0], 1, &C_2_1.data[0][0], 1);
    cblas_daxpy(NS, 0.00010000000000000002, &m14.data[0][0], 1, &C_2_1.data[0][0], 1);
    cblas_daxpy(NS, -1.0, &m16.data[0][0], 1, &C_2_1.data[0][0], 1);
    cblas_daxpy(NS, 1.0, &m2.data[0][0], 1, &C_2_2.data[0][0], 1);
    cblas_daxpy(NS, 1.0, &m5.data[0][0], 1, &C_2_2.data[0][0], 1);
    cblas_daxpy(NS, 1.0, &m9.data[0][0], 1, &C_2_2.data[0][0], 1);
    cblas_daxpy(NS, -1.0, &m1.data[0][0], 1, &C_2_2.data[0][0], 1);
    cblas_daxpy(NS, -1.0, &m12.data[0][0], 1, &C_2_2.data[0][0], 1);
    cblas_daxpy(NS, -1.0, &m8.data[0][0], 1, &C_2_2.data[0][0], 1);
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
    free_double_matrix(m0);
    free_double_matrix(m1);
    free_double_matrix(m2);
    free_double_matrix(m3);
    free_double_matrix(m4);
    free_double_matrix(m5);
    free_double_matrix(m6);
    free_double_matrix(m7);
    free_double_matrix(m8);
    free_double_matrix(m9);
    free_double_matrix(m10);
    free_double_matrix(m11);
    free_double_matrix(m12);
    free_double_matrix(m13);
    free_double_matrix(m14);
    free_double_matrix(m15);
    free_double_matrix(m16);
    free_double_matrix(m17);
    free_double_matrix(m18);
    free_double_matrix(m19);
    free_double_matrix(S0);
    free_double_matrix(S1);
    free_double_matrix(S2);
    free_double_matrix(S3);
    free_double_matrix(S4);
    free_double_matrix(S5);
    free_double_matrix(S6);
    free_double_matrix(S7);
    free_double_matrix(S8);
    free_double_matrix(S9);
    free_double_matrix(S10);
    free_double_matrix(S11);
    free_double_matrix(S12);
    free_double_matrix(S13);
    free_double_matrix(S14);
    free_double_matrix(S15);
    free_double_matrix(S16);
    free_double_matrix(S17);
    free_double_matrix(S18);
    free_double_matrix(S19);
    free_double_matrix(T0);
    free_double_matrix(T1);
    free_double_matrix(T2);
    free_double_matrix(T3);
    free_double_matrix(T4);
    free_double_matrix(T5);
    free_double_matrix(T6);
    free_double_matrix(T7);
    free_double_matrix(T8);
    free_double_matrix(T9);
    free_double_matrix(T10);
    free_double_matrix(T11);
    free_double_matrix(T12);
    free_double_matrix(T13);
    free_double_matrix(T14);
    free_double_matrix(T15);
    free_double_matrix(T16);
    free_double_matrix(T17);
    free_double_matrix(T18);
    free_double_matrix(T19);
    return 0;
}
