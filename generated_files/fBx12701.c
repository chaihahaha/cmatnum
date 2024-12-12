#include "stdafx.h"
#include "fBx12701.h"

inline int fBx12701(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_3_2, bmats.B_6_2, bmats.Bx12659, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx12701.data[0][0], 0, sizeof(bmats.Bx12701.data[0][0])*bmats.Bx12701.shape[0]*bmats.Bx12701.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12701, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
