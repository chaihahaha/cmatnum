#include "fBx13390.h"
#include "stdafx.h"

inline int fBx13390(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 7;
    double_cmat B_mats[7] = {bmats.B_17_31, bmats.B_25_31, bmats.B_26_31, bmats.B_27_31, bmats.B_28_31, bmats.B_29_31, bmats.B_32_31, };
    double B_coeffs[7] = {1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx13390, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
