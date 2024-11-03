#include "fAx1754.h"
#include "stdafx.h"

inline int fAx1754(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_14_10, bmats.A_14_11, bmats.A_14_12, bmats.A_14_13, bmats.A_14_14, bmats.A_14_15, bmats.A_14_16, bmats.A_14_3, bmats.A_14_4, bmats.A_14_5, bmats.A_14_6, bmats.A_14_7, bmats.A_14_8, bmats.A_14_9, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax1754, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
