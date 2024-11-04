#include "stdafx.h"
#include "fAx4708.h"

int fAx4708(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 40;
    double_cmat A_mats[40] = {bmats.A_17_17, bmats.A_17_18, bmats.A_18_18, bmats.A_19_17, bmats.A_19_18, bmats.A_20_17, bmats.A_20_18, bmats.A_21_17, bmats.A_21_18, bmats.A_22_17, bmats.A_22_18, bmats.A_23_17, bmats.A_23_18, bmats.A_24_17, bmats.A_24_18, bmats.A_25_17, bmats.A_25_18, bmats.A_26_17, bmats.A_26_18, bmats.A_27_17, bmats.A_27_18, bmats.A_30_17, bmats.A_30_18, bmats.A_31_17, bmats.A_31_18, bmats.A_32_17, bmats.A_32_18, bmats.Ax100, bmats.Ax118, bmats.Ax164, bmats.Ax171, bmats.Ax1751, bmats.Ax182, bmats.Ax194, bmats.Ax20, bmats.Ax4652, bmats.Ax4655, bmats.Ax64, bmats.Ax673, bmats.Ax85, };
    double A_coeffs[40] = {1, -16, -17, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax4708, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
