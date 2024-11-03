#include "fAx1943.h"
#include "stdafx.h"

inline int fAx1943(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_29_1, bmats.A_29_10, bmats.A_29_11, bmats.A_29_12, bmats.A_29_13, bmats.A_29_14, bmats.A_29_2, bmats.A_29_3, bmats.A_29_4, bmats.A_29_5, bmats.A_29_6, bmats.A_29_7, bmats.A_29_8, bmats.A_29_9, bmats.Ax1899, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(bmats.Ax1943, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
