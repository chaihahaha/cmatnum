#include "stdafx.h"
#include "fBx11458.h"

inline int fBx11458(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_15_7, bmats.Bx9501, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11458.data[0][0], 0, sizeof(bmats.Bx11458.data[0][0])*bmats.Bx11458.shape[0]*bmats.Bx11458.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11458, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
