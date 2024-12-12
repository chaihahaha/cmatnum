#include "stdafx.h"
#include "fBx12682.h"

inline int fBx12682(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 7;
    double_cmat B_mats[7] = {bmats.B_15_10, bmats.B_15_14, bmats.B_15_4, bmats.B_15_6, bmats.B_15_9, bmats.Bx10918, bmats.Bx821, };
    double B_coeffs[7] = {1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx12682.data[0][0], 0, sizeof(bmats.Bx12682.data[0][0])*bmats.Bx12682.shape[0]*bmats.Bx12682.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12682, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
