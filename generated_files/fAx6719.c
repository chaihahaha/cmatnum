#include "stdafx.h"
#include "fAx6719.h"

int fAx6719(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_32_17, bmats.A_32_18, bmats.A_32_19, bmats.A_32_22, bmats.A_32_23, bmats.A_32_24, bmats.A_32_25, bmats.A_32_26, bmats.A_32_27, bmats.A_32_28, bmats.A_32_29, bmats.A_32_30, bmats.A_32_31, bmats.A_32_32, };
    double A_coeffs[14] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, -15, };
    matlincomb_double_contiguous(bmats.Ax6719, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
