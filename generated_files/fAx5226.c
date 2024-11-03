#include "fAx5226.h"
#include "stdafx.h"

inline int fAx5226(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_2_1, bmats.A_2_10, bmats.A_2_13, bmats.A_2_14, bmats.A_2_15, bmats.A_2_16, bmats.A_2_2, bmats.A_2_3, bmats.A_2_4, bmats.A_2_5, bmats.A_2_6, bmats.A_2_7, bmats.A_2_8, bmats.A_2_9, };
    double A_coeffs[14] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax5226, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
