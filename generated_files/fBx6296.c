#include "fBx6296.h"
#include "stdafx.h"

inline int fBx6296(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_12_17, bmats.B_12_18, bmats.B_12_19, bmats.B_12_20, bmats.B_12_21, bmats.B_12_22, bmats.B_12_23, bmats.B_12_24, bmats.B_12_25, bmats.B_12_26, bmats.B_12_27, bmats.B_12_28, bmats.B_12_29, bmats.B_12_30, bmats.B_12_31, bmats.B_12_32, };
    double B_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx6296, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
