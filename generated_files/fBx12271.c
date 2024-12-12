#include "stdafx.h"
#include "fBx12271.h"

inline int fBx12271(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 12;
    double_cmat B_mats[12] = {bmats.B_10_19, bmats.B_11_19, bmats.B_12_19, bmats.B_13_19, bmats.B_14_19, bmats.B_15_19, bmats.B_4_19, bmats.B_5_19, bmats.B_6_19, bmats.B_7_19, bmats.B_8_19, bmats.B_9_19, };
    double B_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx12271.data[0][0], 0, sizeof(bmats.Bx12271.data[0][0])*bmats.Bx12271.shape[0]*bmats.Bx12271.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12271, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
