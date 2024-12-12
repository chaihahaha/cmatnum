#include "stdafx.h"
#include "fBx7382.h"

inline int fBx7382(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_26_9, bmats.B_9_26, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7382.data[0][0], 0, sizeof(bmats.Bx7382.data[0][0])*bmats.Bx7382.shape[0]*bmats.Bx7382.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7382, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
