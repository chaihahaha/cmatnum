#include "fBx13304.h"
#include "stdafx.h"

inline int fBx13304(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 24;
    double_cmat B_mats[24] = {bmats.B_11_12, bmats.B_12_12, bmats.B_13_12, bmats.B_14_12, bmats.B_17_12, bmats.B_18_12, bmats.B_19_12, bmats.B_1_12, bmats.B_20_12, bmats.B_21_12, bmats.B_22_12, bmats.B_23_12, bmats.B_24_12, bmats.B_25_12, bmats.B_26_12, bmats.B_27_12, bmats.B_28_12, bmats.B_29_12, bmats.B_2_12, bmats.B_30_12, bmats.B_31_12, bmats.B_32_12, bmats.B_5_12, bmats.Bx4620, };
    double B_coeffs[24] = {1, 1, 1, 1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx13304, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
