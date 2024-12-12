#include "stdafx.h"
#include "fBx3022.h"

inline int fBx3022(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 1;
    double_cmat B_mats[1] = {bmats.B_13_29, };
    double B_coeffs[1] = {-1, };
memset(&bmats.Bx3022.data[0][0], 0, sizeof(bmats.Bx3022.data[0][0])*bmats.Bx3022.shape[0]*bmats.Bx3022.shape[1]);
    matlincomb_double_contiguous(bmats.Bx3022, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
