#include "fBx9722.h"
#include "stdafx.h"

inline int fBx9722(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 11;
    double_cmat B_mats[11] = {bmats.B_24_10, bmats.B_24_11, bmats.B_24_12, bmats.B_24_13, bmats.B_24_14, bmats.B_24_15, bmats.B_24_16, bmats.B_24_6, bmats.B_24_7, bmats.B_24_8, bmats.B_24_9, };
    double B_coeffs[11] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx9722, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
