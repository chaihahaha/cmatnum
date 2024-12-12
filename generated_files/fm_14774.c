#include "stdafx.h"
#include "fm_14774.h"

inline int fm_14774(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1799, bmats.Axx189, bmats.Axx213, bmats.Axx3041, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.B_16_15, bmats.B_1_15, bmats.B_2_15, bmats.B_3_15, bmats.B_4_15, bmats.B_5_15, bmats.B_6_15, bmats.B_6_2, bmats.Bx10617, bmats.Bx11706, bmats.Bx13220, bmats.Bx13398, bmats.Bx13402, };
    double B_coeffs[13] = {-1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_6_15.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
