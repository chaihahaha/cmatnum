#include "stdafx.h"
#include "fBx3787.h"

inline int fBx3787(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_20_13, bmats.B_7_20, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx3787.data[0][0], 0, sizeof(bmats.Bx3787.data[0][0])*bmats.Bx3787.shape[0]*bmats.Bx3787.shape[1]);
    matlincomb_double_contiguous(bmats.Bx3787, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
