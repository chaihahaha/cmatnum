#include "stdafx.h"
#include "fAxxeval3803.h"

inline int fAxxeval3803(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2696.data[0][0], 0, sizeof(bmats.Axx2696.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_25_1, bmats.A_25_10, bmats.A_25_11, bmats.A_25_12, bmats.A_25_13, bmats.A_25_14, bmats.A_25_15, bmats.A_25_16, bmats.A_25_2, bmats.A_25_3, bmats.A_25_4, bmats.A_25_5, bmats.A_25_6, bmats.A_25_9, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2696, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
