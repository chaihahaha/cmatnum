#include "stdafx.h"
#include "fBx3974.h"

inline int fBx3974(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_19_24, bmats.B_8_29, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx3974.data[0][0], 0, sizeof(bmats.Bx3974.data[0][0])*bmats.Bx3974.shape[0]*bmats.Bx3974.shape[1]);
    matlincomb_double_contiguous(bmats.Bx3974, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
