#include "stdafx.h"
#include "fm_1483.h"

inline int fm_1483(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1024, bmats.Axx454, bmats.Axx483, bmats.Axx485, };
    double A_coeffs[4] = {1, 1, 1, -1, };
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.B_16_5, bmats.B_3_5, bmats.B_7_12, bmats.B_7_4, bmats.B_7_5, bmats.B_7_7, bmats.Bx11185, bmats.Bx11244, bmats.Bx11434, bmats.Bx11437, bmats.Bx11486, bmats.Bx11716, bmats.Bx11717, bmats.Bx2998, bmats.Bx7940, };
    double B_coeffs[15] = {-1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_5.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
