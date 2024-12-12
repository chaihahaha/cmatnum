#include "stdafx.h"
#include "fBx11560.h"

inline int fBx11560(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_16_18, bmats.B_18_5, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11560.data[0][0], 0, sizeof(bmats.Bx11560.data[0][0])*bmats.Bx11560.shape[0]*bmats.Bx11560.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11560, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
