#include "stdafx.h"
#include "fAxxeval7025.h"

inline int fAxxeval7025(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2564.data[0][0], 0, sizeof(bmats.Axx2564.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_21_19, bmats.A_21_20, bmats.A_21_21, bmats.A_21_22, bmats.A_21_23, bmats.A_21_24, bmats.A_21_25, bmats.A_21_26, bmats.A_21_27, bmats.A_21_28, bmats.A_21_29, bmats.A_21_30, bmats.A_21_31, bmats.A_21_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2564, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}