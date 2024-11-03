#include "fAx3111.h"
#include "stdafx.h"

inline int fAx3111(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_10_19, bmats.A_10_20, bmats.A_10_21, bmats.A_10_22, bmats.A_10_23, bmats.A_10_24, bmats.A_10_25, bmats.A_10_26, bmats.A_10_27, bmats.A_10_28, bmats.A_10_29, bmats.A_10_30, bmats.A_10_31, bmats.A_10_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax3111, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
