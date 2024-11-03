#include "fBx13307.h"
#include "stdafx.h"

inline int fBx13307(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_17_28, bmats.B_18_28, bmats.B_19_28, bmats.B_20_28, bmats.B_21_28, bmats.B_22_28, bmats.B_23_28, bmats.B_24_28, bmats.B_25_28, bmats.B_26_28, bmats.B_27_28, bmats.B_28_28, bmats.B_29_28, bmats.B_30_28, bmats.B_31_28, bmats.B_32_28, bmats.Bx4637, };
    double B_coeffs[17] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, };
    matlincomb_double_contiguous(bmats.Bx13307, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
