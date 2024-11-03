#include "fBx11069.h"
#include "stdafx.h"

inline int fBx11069(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_7_17, bmats.B_7_18, bmats.B_7_19, bmats.B_7_20, bmats.B_7_21, bmats.B_7_22, bmats.B_7_23, bmats.B_7_24, bmats.B_7_25, bmats.B_7_26, bmats.B_7_27, bmats.B_7_28, bmats.B_7_29, bmats.B_7_30, bmats.B_7_31, bmats.B_7_32, };
    double B_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx11069, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
