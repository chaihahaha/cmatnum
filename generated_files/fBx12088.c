#include "fBx12088.h"
#include "stdafx.h"

inline int fBx12088(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 12;
    double_cmat B_mats[12] = {bmats.B_17_20, bmats.B_18_20, bmats.B_19_20, bmats.B_20_20, bmats.B_21_20, bmats.B_23_20, bmats.B_24_20, bmats.B_25_20, bmats.B_26_20, bmats.B_27_20, bmats.B_31_20, bmats.B_32_20, };
    double B_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx12088, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
