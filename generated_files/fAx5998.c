#include "stdafx.h"
#include "fAx5998.h"

int fAx5998(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 11;
    double_cmat A_mats[11] = {bmats.A_32_17, bmats.A_32_18, bmats.A_32_19, bmats.A_32_20, bmats.A_32_21, bmats.A_32_24, bmats.A_32_25, bmats.A_32_26, bmats.A_32_27, bmats.A_32_30, bmats.A_32_31, };
    double A_coeffs[11] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax5998, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
