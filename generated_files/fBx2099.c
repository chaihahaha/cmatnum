#include "stdafx.h"
#include "fBx2099.h"

inline int fBx2099(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_14, bmats.B_7_1, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx2099.data[0][0], 0, sizeof(bmats.Bx2099.data[0][0])*bmats.Bx2099.shape[0]*bmats.Bx2099.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2099, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
