#include "stdafx.h"
#include "fBx13006.h"

inline int fBx13006(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_21_17, bmats.B_22_17, bmats.Bx12997, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx13006.data[0][0], 0, sizeof(bmats.Bx13006.data[0][0])*bmats.Bx13006.shape[0]*bmats.Bx13006.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13006, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
