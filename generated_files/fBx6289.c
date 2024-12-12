#include "stdafx.h"
#include "fBx6289.h"

inline int fBx6289(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 8;
    double_cmat B_mats[8] = {bmats.B_12_11, bmats.B_12_3, bmats.B_12_4, bmats.B_12_6, bmats.B_12_8, bmats.Bx1183, bmats.Bx2887, bmats.Bx4541, };
    double B_coeffs[8] = {1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx6289.data[0][0], 0, sizeof(bmats.Bx6289.data[0][0])*bmats.Bx6289.shape[0]*bmats.Bx6289.shape[1]);
    matlincomb_double_contiguous(bmats.Bx6289, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
