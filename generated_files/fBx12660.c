#include "stdafx.h"
#include "fBx12660.h"

inline int fBx12660(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx12658, bmats.Bx12659, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12660.data[0][0], 0, sizeof(bmats.Bx12660.data[0][0])*bmats.Bx12660.shape[0]*bmats.Bx12660.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12660, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}