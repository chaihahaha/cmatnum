#include "fAx3320.h"
#include "stdafx.h"

inline int fAx3320(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 40;
    double_cmat A_mats[40] = {bmats.A_17_25, bmats.A_17_26, bmats.A_18_25, bmats.A_18_26, bmats.A_19_25, bmats.A_19_26, bmats.A_20_25, bmats.A_20_26, bmats.A_21_25, bmats.A_21_26, bmats.A_22_25, bmats.A_22_26, bmats.A_25_25, bmats.A_26_25, bmats.A_26_26, bmats.A_27_25, bmats.A_27_26, bmats.A_28_25, bmats.A_28_26, bmats.A_29_25, bmats.A_29_26, bmats.A_30_25, bmats.A_30_26, bmats.A_31_25, bmats.A_31_26, bmats.A_32_25, bmats.A_32_26, bmats.Ax1494, bmats.Ax2050, bmats.Ax211, bmats.Ax239, bmats.Ax242, bmats.Ax245, bmats.Ax248, bmats.Ax251, bmats.Ax254, bmats.Ax2948, bmats.Ax2952, bmats.Ax4, bmats.Ax58, };
    double A_coeffs[40] = {-16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -17, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax3320, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
