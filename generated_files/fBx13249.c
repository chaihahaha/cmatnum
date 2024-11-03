#include "fBx13249.h"
#include "stdafx.h"

inline int fBx13249(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 20;
    double_cmat B_mats[20] = {bmats.B_16_18, bmats.B_17_18, bmats.B_18_18, bmats.B_19_18, bmats.B_1_18, bmats.B_20_18, bmats.B_21_18, bmats.B_22_18, bmats.B_23_18, bmats.B_24_18, bmats.B_25_18, bmats.B_26_18, bmats.B_27_18, bmats.B_28_18, bmats.B_29_18, bmats.B_2_18, bmats.B_30_18, bmats.B_31_18, bmats.B_32_18, bmats.Bx12672, };
    double B_coeffs[20] = {-1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1, -1, };
    matlincomb_double_contiguous(bmats.Bx13249, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
