#include "stdafx.h"
#include "fAx4714.h"

int fAx4714(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_2_17, bmats.A_2_18, bmats.A_2_19, bmats.A_2_20, bmats.A_2_21, bmats.A_2_22, bmats.A_2_23, bmats.A_2_24, bmats.A_2_27, bmats.A_2_28, bmats.A_2_29, bmats.A_2_30, bmats.A_2_31, bmats.A_2_32, bmats.Ax4678, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(bmats.Ax4714, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
