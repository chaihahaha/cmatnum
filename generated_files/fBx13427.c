#include "stdafx.h"
#include "fBx13427.h"

inline int fBx13427(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_25_31, bmats.B_28_32, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx13427.data[0][0], 0, sizeof(bmats.Bx13427.data[0][0])*bmats.Bx13427.shape[0]*bmats.Bx13427.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13427, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
