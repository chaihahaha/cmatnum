#include "fBx13247.h"
#include "stdafx.h"

inline int fBx13247(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 22;
    double_cmat B_mats[22] = {bmats.B_10_2, bmats.B_14_2, bmats.B_15_2, bmats.B_17_2, bmats.B_18_2, bmats.B_19_2, bmats.B_20_2, bmats.B_21_2, bmats.B_22_2, bmats.B_23_2, bmats.B_24_2, bmats.B_25_2, bmats.B_26_2, bmats.B_27_2, bmats.B_28_2, bmats.B_29_2, bmats.B_30_2, bmats.B_31_2, bmats.B_32_2, bmats.B_4_2, bmats.B_7_2, bmats.Bx12658, };
    double B_coeffs[22] = {1, 1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx13247, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
