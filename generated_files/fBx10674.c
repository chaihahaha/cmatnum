#include "stdafx.h"
#include "fBx10674.h"

inline int fBx10674(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 7;
    double_cmat B_mats[7] = {bmats.B_23_6, bmats.B_24_6, bmats.B_25_6, bmats.B_26_6, bmats.B_28_6, bmats.B_29_6, bmats.Bx10673, };
    double B_coeffs[7] = {1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx10674.data[0][0], 0, sizeof(bmats.Bx10674.data[0][0])*bmats.Bx10674.shape[0]*bmats.Bx10674.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10674, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
