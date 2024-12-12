#include "stdafx.h"
#include "fBx13428.h"

inline int fBx13428(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_28_23, bmats.B_28_25, bmats.Bx10356, bmats.Bx1231, bmats.Bx6292, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx13428.data[0][0], 0, sizeof(bmats.Bx13428.data[0][0])*bmats.Bx13428.shape[0]*bmats.Bx13428.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13428, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
