#include "stdafx.h"
#include "fAxxeval4132.h"

inline int fAxxeval4132(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2986.data[0][0], 0, sizeof(bmats.Axx2986.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_29_10, bmats.A_29_11, bmats.A_29_12, bmats.A_29_13, bmats.A_29_14, bmats.A_29_15, bmats.A_29_16, bmats.A_29_3, bmats.A_29_4, bmats.A_29_5, bmats.A_29_6, bmats.A_29_7, bmats.A_29_8, bmats.A_29_9, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2986, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}