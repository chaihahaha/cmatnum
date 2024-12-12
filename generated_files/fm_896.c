#include "stdafx.h"
#include "fm_896.h"

inline int fm_896(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1991, bmats.Axx1995, bmats.Axx3208, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 12;
    double_cmat B_mats[12] = {bmats.B_3_9, bmats.Bx8318, bmats.Bx8341, bmats.Bx8342, bmats.Bx8343, bmats.Bx8344, bmats.Bx8345, bmats.Bx8346, bmats.Bx8347, bmats.Bx8348, bmats.Bx8350, bmats.Bx8352, };
    double B_coeffs[12] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_31_9.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
