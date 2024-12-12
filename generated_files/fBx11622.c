#include "stdafx.h"
#include "fBx11622.h"

inline int fBx11622(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx3033, bmats.Bx4615, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11622.data[0][0], 0, sizeof(bmats.Bx11622.data[0][0])*bmats.Bx11622.shape[0]*bmats.Bx11622.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11622, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
