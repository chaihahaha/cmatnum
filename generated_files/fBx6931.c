#include "stdafx.h"
#include "fBx6931.h"

inline int fBx6931(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_18_11, bmats.B_1_2, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx6931.data[0][0], 0, sizeof(bmats.Bx6931.data[0][0])*bmats.Bx6931.shape[0]*bmats.Bx6931.shape[1]);
    matlincomb_double_contiguous(bmats.Bx6931, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}