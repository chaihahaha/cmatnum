#include "fBx12700.h"
#include "stdafx.h"

inline int fBx12700(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 8;
    double_cmat B_mats[8] = {bmats.B_11_2, bmats.B_12_2, bmats.B_13_2, bmats.B_14_2, bmats.B_2_2, bmats.B_5_2, bmats.B_8_2, bmats.B_9_2, };
    double B_coeffs[8] = {1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx12700, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
