#include "fAx2306.h"
#include "stdafx.h"

inline int fAx2306(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_8_17, bmats.A_8_18, bmats.A_8_19, bmats.A_8_20, bmats.A_8_21, bmats.A_8_22, bmats.A_8_23, bmats.A_8_24, bmats.A_8_25, bmats.A_8_26, bmats.A_8_29, bmats.A_8_30, bmats.A_8_31, bmats.A_8_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax2306, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
