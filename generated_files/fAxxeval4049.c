#include "stdafx.h"
#include "fAxxeval4049.h"

inline int fAxxeval4049(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2912.data[0][0], 0, sizeof(bmats.Axx2912.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_30_1, bmats.A_30_10, bmats.A_30_11, bmats.A_30_12, bmats.A_30_13, bmats.A_30_14, bmats.A_30_15, bmats.A_30_16, bmats.A_30_2, bmats.A_30_3, bmats.A_30_4, bmats.A_30_7, bmats.A_30_8, bmats.A_30_9, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2912, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}