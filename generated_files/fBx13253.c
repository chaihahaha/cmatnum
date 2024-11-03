#include "fBx13253.h"
#include "stdafx.h"

inline int fBx13253(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 21;
    double_cmat B_mats[21] = {bmats.B_16_19, bmats.B_17_19, bmats.B_18_19, bmats.B_19_19, bmats.B_1_19, bmats.B_20_19, bmats.B_21_19, bmats.B_22_19, bmats.B_23_19, bmats.B_24_19, bmats.B_25_19, bmats.B_26_19, bmats.B_27_19, bmats.B_28_19, bmats.B_29_19, bmats.B_2_19, bmats.B_30_19, bmats.B_31_19, bmats.B_32_19, bmats.B_3_19, bmats.Bx12271, };
    double B_coeffs[21] = {-1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1, -1, -1, };
    matlincomb_double_contiguous(bmats.Bx13253, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
