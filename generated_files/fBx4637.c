#include "fBx4637.h"
#include "stdafx.h"

inline int fBx4637(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_10_28, bmats.B_11_28, bmats.B_12_28, bmats.B_13_28, bmats.B_14_28, bmats.B_15_28, bmats.B_16_28, bmats.B_1_28, bmats.B_2_28, bmats.B_3_28, bmats.B_4_28, bmats.B_5_28, bmats.B_6_28, bmats.B_7_28, bmats.B_8_28, bmats.B_9_28, };
    double B_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx4637, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
