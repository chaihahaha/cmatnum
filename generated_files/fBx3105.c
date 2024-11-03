#include "fBx3105.h"
#include "stdafx.h"

inline int fBx3105(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_14_3, bmats.B_14_4, bmats.B_14_6, bmats.B_14_7, bmats.B_14_8, bmats.B_14_9, };
    double B_coeffs[6] = {1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx3105, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
