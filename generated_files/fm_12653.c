#include "fm_12653.h"
#include "stdafx.h"

inline int fm_12653(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_12_27, bmats.A_12_28, bmats.A_28_13, bmats.A_28_14, bmats.A_29_17, bmats.A_29_18, bmats.A_29_19, bmats.A_29_20, bmats.A_29_28, bmats.A_29_29, bmats.A_29_30, bmats.Ax2294, bmats.Ax491, bmats.Ax7538, };
    double A_coeffs[14] = {-1, 16, 16, -1, 1, 1, 1, 1, -16, 1, 1, -1, -1, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_13_28, bmats.B_28_12, bmats.B_28_29, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_29_12.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_28_28.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_12_29.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
