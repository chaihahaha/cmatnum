#include "stdafx.h"
#include "fBx12712.h"

inline int fBx12712(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx12662, bmats.Bx12676, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12712.data[0][0], 0, sizeof(bmats.Bx12712.data[0][0])*bmats.Bx12712.shape[0]*bmats.Bx12712.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12712, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}