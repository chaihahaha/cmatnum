#include "stdafx.h"
#include "fBx11248.h"

inline int fBx11248(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_23_17, bmats.B_23_22, bmats.Bx10391, bmats.Bx5095, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx11248.data[0][0], 0, sizeof(bmats.Bx11248.data[0][0])*bmats.Bx11248.shape[0]*bmats.Bx11248.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11248, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
