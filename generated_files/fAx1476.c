#include "fAx1476.h"
#include "stdafx.h"

inline int fAx1476(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_30_1, bmats.A_30_10, bmats.A_30_11, bmats.A_30_12, bmats.A_30_13, bmats.A_30_14, bmats.A_30_15, bmats.A_30_16, bmats.A_30_2, bmats.A_30_3, bmats.A_30_4, bmats.A_30_5, bmats.A_30_6, bmats.A_30_7, bmats.Ax443, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(bmats.Ax1476, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
