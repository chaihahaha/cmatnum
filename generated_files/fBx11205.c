#include "stdafx.h"
#include "fBx11205.h"

inline int fBx11205(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_22_20, bmats.B_22_32, bmats.Bx10627, bmats.Bx1967, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx11205.data[0][0], 0, sizeof(bmats.Bx11205.data[0][0])*bmats.Bx11205.shape[0]*bmats.Bx11205.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11205, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
