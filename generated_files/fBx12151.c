#include "fBx12151.h"
#include "stdafx.h"

inline int fBx12151(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.B_24_1, bmats.B_24_15, bmats.B_24_16, bmats.B_24_2, bmats.B_24_3, bmats.B_24_4, bmats.B_24_5, bmats.B_24_6, bmats.B_24_7, bmats.B_24_8, };
    double B_coeffs[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx12151, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
