#include "stdafx.h"
#include "fBx12875.h"

inline int fBx12875(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_31_32, bmats.B_32_17, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12875.data[0][0], 0, sizeof(bmats.Bx12875.data[0][0])*bmats.Bx12875.shape[0]*bmats.Bx12875.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12875, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
