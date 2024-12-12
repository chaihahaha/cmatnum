#include "stdafx.h"
#include "fBx13420.h"

inline int fBx13420(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx13389, bmats.Bx13419, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx13420.data[0][0], 0, sizeof(bmats.Bx13420.data[0][0])*bmats.Bx13420.shape[0]*bmats.Bx13420.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13420, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
