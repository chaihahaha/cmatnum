#include "stdafx.h"
#include "fAxxeval7542.h"

inline int fAxxeval7542(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2031.data[0][0], 0, sizeof(bmats.Axx2031.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_26_17, bmats.A_26_18, bmats.A_26_19, bmats.A_26_20, bmats.A_26_21, bmats.A_26_22, bmats.A_26_25, bmats.A_26_26, bmats.A_26_27, bmats.A_26_28, bmats.A_26_29, bmats.A_26_30, bmats.A_26_31, bmats.A_26_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2031, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}