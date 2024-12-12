#include "stdafx.h"
#include "fBx357.h"

inline int fBx357(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_7, bmats.B_23_31, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx357.data[0][0], 0, sizeof(bmats.Bx357.data[0][0])*bmats.Bx357.shape[0]*bmats.Bx357.shape[1]);
    matlincomb_double_contiguous(bmats.Bx357, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
