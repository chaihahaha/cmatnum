#include "stdafx.h"
#include "fAxxeval2803.h"

inline int fAxxeval2803(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx395.data[0][0], 0, sizeof(bmats.Axx395.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_13_1, bmats.A_13_11, bmats.A_13_12, bmats.A_13_13, bmats.A_13_14, bmats.A_13_15, bmats.A_13_16, bmats.A_13_2, bmats.A_13_3, bmats.A_13_4, bmats.A_13_5, bmats.A_13_6, bmats.A_13_7, bmats.A_13_8, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx395, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}