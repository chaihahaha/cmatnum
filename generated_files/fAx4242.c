#include "fAx4242.h"
#include "stdafx.h"

inline int fAx4242(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_5_1, bmats.A_5_10, bmats.A_5_11, bmats.A_5_12, bmats.A_5_13, bmats.A_5_14, bmats.A_5_15, bmats.A_5_16, bmats.A_5_2, bmats.A_5_5, bmats.A_5_6, bmats.A_5_7, bmats.A_5_8, bmats.A_5_9, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax4242, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
