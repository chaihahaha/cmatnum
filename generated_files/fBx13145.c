#include "stdafx.h"
#include "fBx13145.h"

inline int fBx13145(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_6_7, bmats.B_7_6, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx13145.data[0][0], 0, sizeof(bmats.Bx13145.data[0][0])*bmats.Bx13145.shape[0]*bmats.Bx13145.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13145, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}