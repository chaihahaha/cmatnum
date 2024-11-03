#include "fm_837.h"
#include "stdafx.h"

inline int fm_837(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_10_32, bmats.A_26_25, bmats.A_26_26, bmats.Ax1566, bmats.Ax2836, bmats.Ax58, };
    double A_coeffs[6] = {-1, 1, -16, 1, 1, 1, };
    int n_B_mats = 25;
    double_cmat B_mats[25] = {bmats.B_10_26, bmats.B_17_26, bmats.B_18_26, bmats.B_19_26, bmats.B_20_26, bmats.B_21_26, bmats.B_22_26, bmats.B_23_26, bmats.B_24_26, bmats.B_25_26, bmats.B_26_1, bmats.B_26_2, bmats.B_26_26, bmats.B_26_3, bmats.B_26_4, bmats.B_26_5, bmats.B_26_6, bmats.B_26_7, bmats.B_27_26, bmats.B_28_26, bmats.B_29_26, bmats.B_30_26, bmats.B_31_26, bmats.B_32_26, bmats.Bx7705, };
    double B_coeffs[25] = {1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_10_26.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
