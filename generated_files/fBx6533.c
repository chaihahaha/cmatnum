#include "stdafx.h"
#include "fBx6533.h"

inline int fBx6533(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_25_18, bmats.B_2_27, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx6533.data[0][0], 0, sizeof(bmats.Bx6533.data[0][0])*bmats.Bx6533.shape[0]*bmats.Bx6533.shape[1]);
    matlincomb_double_contiguous(bmats.Bx6533, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}