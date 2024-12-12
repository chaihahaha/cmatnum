#include "stdafx.h"
#include "fBx7120.h"

inline int fBx7120(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_22_11, bmats.B_3_6, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7120.data[0][0], 0, sizeof(bmats.Bx7120.data[0][0])*bmats.Bx7120.shape[0]*bmats.Bx7120.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7120, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
