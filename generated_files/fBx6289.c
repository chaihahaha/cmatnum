#include "fBx6289.h"
#include "stdafx.h"

inline int fBx6289(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 11;
    double_cmat B_mats[11] = {bmats.B_12_1, bmats.B_12_10, bmats.B_12_11, bmats.B_12_13, bmats.B_12_15, bmats.B_12_16, bmats.B_12_2, bmats.B_12_3, bmats.B_12_4, bmats.B_12_6, bmats.B_12_8, };
    double B_coeffs[11] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx6289, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
