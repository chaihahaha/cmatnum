#include "fm_920.h"
#include "stdafx.h"

inline int fm_920(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_12_31, bmats.A_25_27, bmats.A_25_28, bmats.Ax1309, bmats.Ax3157, bmats.Ax55, };
    double A_coeffs[6] = {-1, 1, -16, 1, 1, 1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_17_25, bmats.B_18_25, bmats.B_19_25, bmats.B_25_25, bmats.B_26_25, bmats.B_27_25, bmats.B_28_12, bmats.B_28_13, bmats.B_28_14, bmats.B_28_15, bmats.B_28_16, bmats.B_28_25, bmats.B_29_25, bmats.B_30_25, bmats.B_9_28, bmats.Bx6294, bmats.Bx8256, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_12_25.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
