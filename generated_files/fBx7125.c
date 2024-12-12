#include "stdafx.h"
#include "fBx7125.h"

inline int fBx7125(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_3_11, bmats.Bx2315, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7125.data[0][0], 0, sizeof(bmats.Bx7125.data[0][0])*bmats.Bx7125.shape[0]*bmats.Bx7125.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7125, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
