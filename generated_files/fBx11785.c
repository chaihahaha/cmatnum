#include "stdafx.h"
#include "fBx11785.h"

inline int fBx11785(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx10844, bmats.Bx11784, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11785.data[0][0], 0, sizeof(bmats.Bx11785.data[0][0])*bmats.Bx11785.shape[0]*bmats.Bx11785.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11785, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
