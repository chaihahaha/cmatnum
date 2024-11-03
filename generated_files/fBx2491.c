#include "fBx2491.h"
#include "stdafx.h"

inline int fBx2491(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.B_30_10, bmats.B_30_11, bmats.B_30_12, bmats.B_30_13, bmats.B_30_14, bmats.B_30_15, bmats.B_30_16, bmats.B_30_2, bmats.B_30_3, bmats.B_30_4, bmats.B_30_5, bmats.B_30_6, bmats.B_30_7, bmats.B_30_8, bmats.B_30_9, };
    double B_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx2491, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
