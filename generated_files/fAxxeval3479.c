#include "stdafx.h"
#include "fAxxeval3479.h"

inline int fAxxeval3479(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2415.data[0][0], 0, sizeof(bmats.Axx2415.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_20_10, bmats.A_20_11, bmats.A_20_12, bmats.A_20_13, bmats.A_20_14, bmats.A_20_15, bmats.A_20_16, bmats.A_20_3, bmats.A_20_4, bmats.A_20_5, bmats.A_20_6, bmats.A_20_7, bmats.A_20_8, bmats.A_20_9, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2415, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
