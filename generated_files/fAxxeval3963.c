#include "stdafx.h"
#include "fAxxeval3963.h"

inline int fAxxeval3963(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2836.data[0][0], 0, sizeof(bmats.Axx2836.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_23_1, bmats.A_23_10, bmats.A_23_11, bmats.A_23_12, bmats.A_23_13, bmats.A_23_14, bmats.A_23_15, bmats.A_23_16, bmats.A_23_2, bmats.A_23_5, bmats.A_23_6, bmats.A_23_7, bmats.A_23_8, bmats.A_23_9, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2836, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
