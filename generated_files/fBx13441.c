#include "fBx13441.h"
#include "stdafx.h"

inline int fBx13441(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.B_18_32, bmats.B_19_32, bmats.B_20_32, bmats.B_21_32, bmats.B_22_32, bmats.B_23_32, bmats.B_24_32, bmats.B_26_32, bmats.B_27_32, bmats.B_29_32, bmats.B_30_32, bmats.B_31_32, bmats.B_32_32, };
    double B_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx13441, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
