#include "stdafx.h"
#include "fBx11639.h"

inline int fBx11639(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_30_18, bmats.B_30_19, bmats.B_30_23, bmats.B_30_31, bmats.Bx10262, bmats.Bx2480, };
    double B_coeffs[6] = {1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx11639.data[0][0], 0, sizeof(bmats.Bx11639.data[0][0])*bmats.Bx11639.shape[0]*bmats.Bx11639.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11639, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
