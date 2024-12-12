#include "stdafx.h"
#include "fAxxeval2286.h"

inline int fAxxeval2286(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1917.data[0][0], 0, sizeof(bmats.Axx1917.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_3_10, bmats.A_3_11, bmats.A_3_12, bmats.A_3_13, bmats.A_3_14, bmats.A_3_15, bmats.A_3_16, bmats.A_3_3, bmats.A_3_4, bmats.A_3_5, bmats.A_3_6, bmats.A_3_7, bmats.A_3_8, bmats.A_3_9, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1917, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
