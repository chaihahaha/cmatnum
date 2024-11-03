#include "fBx11462.h"
#include "stdafx.h"

inline int fBx11462(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 8;
    double_cmat B_mats[8] = {bmats.B_21_21, bmats.B_22_21, bmats.B_24_21, bmats.B_25_21, bmats.B_26_21, bmats.B_28_21, bmats.B_29_21, bmats.B_30_21, };
    double B_coeffs[8] = {1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx11462, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
