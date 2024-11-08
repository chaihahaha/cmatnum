#include "stdafx.h"
#include "fAx4225.h"

int fAx4225(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 40;
    double_cmat A_mats[40] = {bmats.A_17_21, bmats.A_17_22, bmats.A_18_21, bmats.A_18_22, bmats.A_20_21, bmats.A_20_22, bmats.A_21_21, bmats.A_22_21, bmats.A_22_22, bmats.A_23_21, bmats.A_23_22, bmats.A_25_21, bmats.A_25_22, bmats.A_26_21, bmats.A_26_22, bmats.A_27_21, bmats.A_27_22, bmats.A_28_21, bmats.A_28_22, bmats.A_29_21, bmats.A_29_22, bmats.A_30_21, bmats.A_30_22, bmats.A_31_21, bmats.A_31_22, bmats.A_32_21, bmats.A_32_22, bmats.Ax128, bmats.Ax1635, bmats.Ax179, bmats.Ax204, bmats.Ax2083, bmats.Ax3930, bmats.Ax3934, bmats.Ax3940, bmats.Ax3943, bmats.Ax3949, bmats.Ax42, bmats.Ax74, bmats.Ax93, };
    double A_coeffs[40] = {-16, 1, -16, 1, -16, 1, -17, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax4225, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
