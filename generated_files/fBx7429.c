#include "stdafx.h"
#include "fBx7429.h"

int fBx7429(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_11_17, bmats.B_11_18, bmats.B_11_19, bmats.B_11_20, bmats.B_11_21, bmats.B_11_22, bmats.B_11_23, bmats.B_11_24, bmats.B_11_25, bmats.B_11_26, bmats.B_11_27, bmats.B_11_28, bmats.B_11_29, bmats.B_11_30, bmats.B_11_31, bmats.B_11_32, };
    double B_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx7429, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
