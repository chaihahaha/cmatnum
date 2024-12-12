#include "stdafx.h"
#include "fBx3137.h"

inline int fBx3137(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_29, bmats.B_24_1, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx3137.data[0][0], 0, sizeof(bmats.Bx3137.data[0][0])*bmats.Bx3137.shape[0]*bmats.Bx3137.shape[1]);
    matlincomb_double_contiguous(bmats.Bx3137, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
