#include "stdafx.h"
#include "fBx10332.h"

inline int fBx10332(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx10045, bmats.Bx10254, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx10332.data[0][0], 0, sizeof(bmats.Bx10332.data[0][0])*bmats.Bx10332.shape[0]*bmats.Bx10332.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10332, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
