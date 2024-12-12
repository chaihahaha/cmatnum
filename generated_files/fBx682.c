#include "stdafx.h"
#include "fBx682.h"

inline int fBx682(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_13_24, bmats.B_24_14, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx682.data[0][0], 0, sizeof(bmats.Bx682.data[0][0])*bmats.Bx682.shape[0]*bmats.Bx682.shape[1]);
    matlincomb_double_contiguous(bmats.Bx682, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
