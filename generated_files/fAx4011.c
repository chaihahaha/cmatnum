#include "stdafx.h"
#include "fAx4011.h"

int fAx4011(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_6_17, bmats.A_6_18, bmats.A_6_19, bmats.A_6_20, bmats.A_6_21, bmats.A_6_22, bmats.A_6_24, bmats.A_6_25, bmats.A_6_26, bmats.A_6_27, bmats.A_6_28, bmats.A_6_30, bmats.A_6_31, bmats.A_6_32, bmats.Ax3987, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(bmats.Ax4011, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
