#include "fBx9527.h"
#include "stdafx.h"

inline int fBx9527(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_9_17, bmats.B_9_18, bmats.B_9_19, bmats.B_9_20, bmats.B_9_21, bmats.B_9_22, bmats.B_9_23, bmats.B_9_24, bmats.B_9_25, bmats.B_9_26, bmats.B_9_27, bmats.B_9_28, bmats.B_9_29, bmats.B_9_30, bmats.B_9_31, bmats.B_9_32, };
    double B_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx9527, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
