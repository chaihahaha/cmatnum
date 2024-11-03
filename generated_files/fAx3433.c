#include "fAx3433.h"
#include "stdafx.h"

inline int fAx3433(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_3_17, bmats.A_3_18, bmats.A_3_19, bmats.A_3_20, bmats.A_3_21, bmats.A_3_22, bmats.A_3_25, bmats.A_3_26, bmats.A_3_27, bmats.A_3_28, bmats.A_3_29, bmats.A_3_30, bmats.A_3_31, bmats.A_3_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax3433, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
