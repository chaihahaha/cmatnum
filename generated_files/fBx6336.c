#include "stdafx.h"
#include "fBx6336.h"

inline int fBx6336(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_20_11, bmats.B_7_4, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx6336.data[0][0], 0, sizeof(bmats.Bx6336.data[0][0])*bmats.Bx6336.shape[0]*bmats.Bx6336.shape[1]);
    matlincomb_double_contiguous(bmats.Bx6336, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}