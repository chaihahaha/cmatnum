#include "stdafx.h"
#include "fBx2409.h"

inline int fBx2409(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_18_14, bmats.B_3_18, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx2409.data[0][0], 0, sizeof(bmats.Bx2409.data[0][0])*bmats.Bx2409.shape[0]*bmats.Bx2409.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2409, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}