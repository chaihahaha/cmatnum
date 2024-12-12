#include "stdafx.h"
#include "fBx6243.h"

inline int fBx6243(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_11_23, bmats.B_7_11, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx6243.data[0][0], 0, sizeof(bmats.Bx6243.data[0][0])*bmats.Bx6243.shape[0]*bmats.Bx6243.shape[1]);
    matlincomb_double_contiguous(bmats.Bx6243, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
