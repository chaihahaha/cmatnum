#include "stdafx.h"
#include "fAxxeval4621.h"

inline int fAxxeval4621(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3340.data[0][0], 0, sizeof(bmats.Axx3340.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_32_10, bmats.A_32_11, bmats.A_32_12, bmats.A_32_13, bmats.A_32_14, bmats.A_32_15, bmats.A_32_16, bmats.A_32_3, bmats.A_32_4, bmats.A_32_5, bmats.A_32_6, bmats.A_32_7, bmats.A_32_8, bmats.A_32_9, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3340, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
