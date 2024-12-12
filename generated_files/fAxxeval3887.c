#include "stdafx.h"
#include "fAxxeval3887.h"

inline int fAxxeval3887(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2769.data[0][0], 0, sizeof(bmats.Axx2769.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_24_1, bmats.A_24_10, bmats.A_24_11, bmats.A_24_12, bmats.A_24_13, bmats.A_24_14, bmats.A_24_15, bmats.A_24_16, bmats.A_24_2, bmats.A_24_3, bmats.A_24_4, bmats.A_24_5, bmats.A_24_6, bmats.A_24_9, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2769, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
