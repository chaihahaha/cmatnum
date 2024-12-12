#include "stdafx.h"
#include "fBx9738.h"

inline int fBx9738(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_24_8, bmats.B_8_24, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx9738.data[0][0], 0, sizeof(bmats.Bx9738.data[0][0])*bmats.Bx9738.shape[0]*bmats.Bx9738.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9738, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
