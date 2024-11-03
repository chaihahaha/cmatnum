#include "fm_12421.h"
#include "stdafx.h"

inline int fm_12421(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_27_13, bmats.A_27_14, bmats.A_30_18, bmats.A_30_20, bmats.A_30_27, bmats.A_30_28, bmats.A_30_29, bmats.A_30_30, bmats.A_30_31, bmats.A_30_32, bmats.A_4_27, bmats.A_4_28, bmats.Ax2318, bmats.Ax488, bmats.Ax8025, };
    double A_coeffs[15] = {-1, 16, 1, -16, 1, 1, 1, 1, 1, 1, 16, -1, -1, -1, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_14_20, bmats.B_20_11, bmats.B_27_30, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_30_11.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_27_20.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_4_30.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
