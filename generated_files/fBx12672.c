#include "stdafx.h"
#include "fBx12672.h"

inline int fBx12672(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.B_10_18, bmats.B_11_18, bmats.B_12_18, bmats.B_13_18, bmats.B_14_18, bmats.B_15_18, bmats.B_3_18, bmats.B_4_18, bmats.B_5_18, bmats.B_6_18, bmats.B_7_18, bmats.B_8_18, bmats.B_9_18, };
    double B_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx12672.data[0][0], 0, sizeof(bmats.Bx12672.data[0][0])*bmats.Bx12672.shape[0]*bmats.Bx12672.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12672, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
