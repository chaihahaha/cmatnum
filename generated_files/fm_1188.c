#include "stdafx.h"
#include "fm_1188.h"

inline int fm_1188(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1045, bmats.Axx1068, bmats.Axx2621, bmats.Axx980, };
    double A_coeffs[4] = {-1, 1, 1, 1, };
    int n_B_mats = 11;
    double_cmat B_mats[11] = {bmats.B_21_23, bmats.B_22_23, bmats.B_27_23, bmats.B_32_23, bmats.Bx10232, bmats.Bx10235, bmats.Bx10342, bmats.Bx10343, bmats.Bx10344, bmats.Bx10346, bmats.Bx7425, };
    double B_coeffs[11] = {-1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_27_23.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
