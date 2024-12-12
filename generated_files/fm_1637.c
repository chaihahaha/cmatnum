#include "stdafx.h"
#include "fm_1637.h"

inline int fm_1637(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1521, bmats.Axx1630, bmats.Axx1958, bmats.Axx3388, };
    double A_coeffs[4] = {-1, -1, -1, -1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_10_20, bmats.B_11_20, bmats.B_12_20, bmats.B_13_20, bmats.B_21_10, bmats.B_21_11, bmats.B_21_12, bmats.B_21_13, bmats.B_21_9, bmats.B_5_20, bmats.B_7_20, bmats.B_8_20, bmats.B_9_20, bmats.Bx11170, bmats.Bx12112, bmats.Bx12238, bmats.Bx12254, bmats.Bx804, };
    double B_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_5_20.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
