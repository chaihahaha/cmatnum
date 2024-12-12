#include "stdafx.h"
#include "fBx10720.h"

inline int fBx10720(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_1_17, bmats.B_1_7, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx10720.data[0][0], 0, sizeof(bmats.Bx10720.data[0][0])*bmats.Bx10720.shape[0]*bmats.Bx10720.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10720, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
