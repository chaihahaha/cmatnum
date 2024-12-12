#include "stdafx.h"
#include "fAxxeval3645.h"

inline int fAxxeval3645(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2556.data[0][0], 0, sizeof(bmats.Axx2556.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_18_1, bmats.A_18_10, bmats.A_18_11, bmats.A_18_12, bmats.A_18_13, bmats.A_18_14, bmats.A_18_15, bmats.A_18_16, bmats.A_18_2, bmats.A_18_3, bmats.A_18_4, bmats.A_18_5, bmats.A_18_6, bmats.A_18_9, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2556, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
