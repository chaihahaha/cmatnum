#include "stdafx.h"
#include "fm_1187.h"

inline int fm_1187(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1559, bmats.Axx1889, bmats.Axx758, bmats.Axx778, };
    double A_coeffs[4] = {1, 1, 1, -1, };
    int n_B_mats = 14;
    double_cmat B_mats[14] = {bmats.B_11_11, bmats.B_11_12, bmats.B_11_3, bmats.B_11_7, bmats.B_3_7, bmats.Bx10255, bmats.Bx10337, bmats.Bx10338, bmats.Bx10339, bmats.Bx10340, bmats.Bx10341, bmats.Bx2994, bmats.Bx7410, bmats.Bx7673, };
    double B_coeffs[14] = {-1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_11_7.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
