#include "fBx3115.h"
#include "stdafx.h"

inline int fBx3115(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 9;
    double_cmat B_mats[9] = {bmats.B_14_1, bmats.B_14_10, bmats.B_14_11, bmats.B_14_13, bmats.B_14_14, bmats.B_14_15, bmats.B_14_16, bmats.B_14_2, bmats.B_14_5, };
    double B_coeffs[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx3115, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
