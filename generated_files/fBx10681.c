#include "stdafx.h"
#include "fBx10681.h"

inline int fBx10681(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx10045, bmats.Bx10252, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx10681.data[0][0], 0, sizeof(bmats.Bx10681.data[0][0])*bmats.Bx10681.shape[0]*bmats.Bx10681.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10681, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}