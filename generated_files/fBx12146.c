#include "stdafx.h"
#include "fBx12146.h"

inline int fBx12146(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_26_20, bmats.B_30_20, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12146.data[0][0], 0, sizeof(bmats.Bx12146.data[0][0])*bmats.Bx12146.shape[0]*bmats.Bx12146.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12146, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}