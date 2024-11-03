#include "fBx12870.h"
#include "stdafx.h"

inline int fBx12870(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 9;
    double_cmat B_mats[9] = {bmats.B_10_1, bmats.B_11_1, bmats.B_12_1, bmats.B_13_1, bmats.B_1_1, bmats.B_2_1, bmats.B_3_1, bmats.B_8_1, bmats.B_9_1, };
    double B_coeffs[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx12870, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
