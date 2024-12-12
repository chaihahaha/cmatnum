#include "stdafx.h"
#include "fBx7512.h"

inline int fBx7512(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_22_10, bmats.B_8_6, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7512.data[0][0], 0, sizeof(bmats.Bx7512.data[0][0])*bmats.Bx7512.shape[0]*bmats.Bx7512.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7512, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
