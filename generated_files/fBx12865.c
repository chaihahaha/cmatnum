#include "fBx12865.h"
#include "stdafx.h"

inline int fBx12865(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.B_19_1, bmats.B_20_1, bmats.B_21_1, bmats.B_22_1, bmats.B_23_1, bmats.B_24_1, bmats.B_25_1, bmats.B_26_1, bmats.B_27_1, bmats.B_28_1, bmats.B_29_1, bmats.B_30_1, bmats.B_31_1, };
    double B_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx12865, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
