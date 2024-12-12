#include "stdafx.h"
#include "fBx6845.h"

inline int fBx6845(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_2_11, bmats.B_6_18, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx6845.data[0][0], 0, sizeof(bmats.Bx6845.data[0][0])*bmats.Bx6845.shape[0]*bmats.Bx6845.shape[1]);
    matlincomb_double_contiguous(bmats.Bx6845, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
