#include "fAx3905.h"
#include "stdafx.h"

inline int fAx3905(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_22_1, bmats.A_22_10, bmats.A_22_11, bmats.A_22_12, bmats.A_22_15, bmats.A_22_16, bmats.A_22_2, bmats.A_22_3, bmats.A_22_4, bmats.A_22_5, bmats.A_22_6, bmats.A_22_7, bmats.A_22_8, bmats.A_22_9, bmats.Ax3867, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(bmats.Ax3905, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
