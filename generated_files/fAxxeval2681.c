#include "stdafx.h"
#include "fAxxeval2681.h"

inline int fAxxeval2681(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx763.data[0][0], 0, sizeof(bmats.Axx763.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_7_10, bmats.A_7_11, bmats.A_7_12, bmats.A_7_13, bmats.A_7_14, bmats.A_7_15, bmats.A_7_16, bmats.A_7_3, bmats.A_7_4, bmats.A_7_5, bmats.A_7_6, bmats.A_7_7, bmats.A_7_8, bmats.A_7_9, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx763, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
