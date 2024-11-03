#include "fBx13355.h"
#include "stdafx.h"

inline int fBx13355(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 7;
    double_cmat B_mats[7] = {bmats.B_11_16, bmats.B_13_16, bmats.B_14_16, bmats.B_16_16, bmats.B_4_16, bmats.B_6_16, bmats.B_7_16, };
    double B_coeffs[7] = {1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx13355, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
