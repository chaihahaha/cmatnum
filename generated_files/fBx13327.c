#include "stdafx.h"
#include "fBx13327.h"

inline int fBx13327(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_10_13, bmats.B_13_10, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx13327.data[0][0], 0, sizeof(bmats.Bx13327.data[0][0])*bmats.Bx13327.shape[0]*bmats.Bx13327.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13327, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
