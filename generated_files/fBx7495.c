#include "stdafx.h"
#include "fBx7495.h"

inline int fBx7495(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_6_10, bmats.B_8_6, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7495.data[0][0], 0, sizeof(bmats.Bx7495.data[0][0])*bmats.Bx7495.shape[0]*bmats.Bx7495.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7495, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}