#include "stdafx.h"
#include "fAxxeval2412.h"

inline int fAxxeval2412(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1631.data[0][0], 0, sizeof(bmats.Axx1631.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_10_1, bmats.A_10_10, bmats.A_10_11, bmats.A_10_12, bmats.A_10_13, bmats.A_10_14, bmats.A_10_15, bmats.A_10_16, bmats.A_10_2, bmats.A_10_5, bmats.A_10_6, bmats.A_10_7, bmats.A_10_8, bmats.A_10_9, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1631, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}