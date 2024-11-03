#include "fBx10240.h"
#include "stdafx.h"

inline int fBx10240(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.B_17_7, bmats.B_18_7, bmats.B_19_7, bmats.B_20_7, bmats.B_21_7, bmats.B_22_7, bmats.B_23_7, bmats.B_31_7, bmats.B_32_7, bmats.Bx10008, };
    double B_coeffs[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx10240, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
