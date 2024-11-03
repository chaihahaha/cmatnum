#include "fm_1224.h"
#include "stdafx.h"

inline int fm_1224(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_23_25, bmats.A_23_26, bmats.A_9_30, bmats.Ax1512, bmats.Ax236, bmats.Ax3692, };
    double A_coeffs[6] = {-16, 1, -1, 1, 1, 1, };
    int n_B_mats = 21;
    double_cmat B_mats[21] = {bmats.B_17_23, bmats.B_18_23, bmats.B_19_23, bmats.B_20_23, bmats.B_21_23, bmats.B_22_23, bmats.B_25_10, bmats.B_25_11, bmats.B_25_12, bmats.B_25_13, bmats.B_25_14, bmats.B_25_15, bmats.B_25_16, bmats.B_25_9, bmats.B_26_23, bmats.B_30_23, bmats.B_31_23, bmats.B_32_23, bmats.B_7_25, bmats.Bx9525, bmats.Bx9994, };
    double B_coeffs[21] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_23.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
