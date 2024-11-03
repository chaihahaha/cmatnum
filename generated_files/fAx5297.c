#include "fAx5297.h"
#include "stdafx.h"

inline int fAx5297(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_14_1, bmats.A_14_11, bmats.A_14_12, bmats.A_14_13, bmats.A_14_15, bmats.A_14_16, bmats.A_14_2, bmats.A_14_3, bmats.A_14_4, bmats.A_14_5, bmats.A_14_6, bmats.A_14_7, bmats.A_14_8, };
    double A_coeffs[13] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax5297, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
