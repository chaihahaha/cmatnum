#include "fm_12349.h"
#include "stdafx.h"

inline int fm_12349(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_12_31, bmats.A_12_32, bmats.A_30_18, bmats.A_30_20, bmats.A_30_27, bmats.A_30_28, bmats.A_30_29, bmats.A_30_30, bmats.A_30_31, bmats.A_30_32, bmats.A_32_13, bmats.A_32_14, bmats.Ax485, bmats.Ax757, bmats.Ax8025, };
    double A_coeffs[15] = {-1, 16, 1, 1, 1, -16, 1, 1, 1, 1, -1, 16, -1, -1, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_14_28, bmats.B_28_16, bmats.B_32_30, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_30_16.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_32_28.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_12_30.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
