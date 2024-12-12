#include "stdafx.h"
#include "fBx11061.h"

inline int fBx11061(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_21_22, bmats.B_22_22, bmats.B_32_22, bmats.Bx10901, bmats.Bx10913, bmats.Bx11051, };
    double B_coeffs[6] = {1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx11061.data[0][0], 0, sizeof(bmats.Bx11061.data[0][0])*bmats.Bx11061.shape[0]*bmats.Bx11061.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11061, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
