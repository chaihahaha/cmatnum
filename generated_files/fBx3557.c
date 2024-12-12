#include "stdafx.h"
#include "fBx3557.h"

inline int fBx3557(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_32_13, bmats.B_5_32, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx3557.data[0][0], 0, sizeof(bmats.Bx3557.data[0][0])*bmats.Bx3557.shape[0]*bmats.Bx3557.shape[1]);
    matlincomb_double_contiguous(bmats.Bx3557, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
