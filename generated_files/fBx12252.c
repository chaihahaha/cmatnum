#include "stdafx.h"
#include "fBx12252.h"

inline int fBx12252(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_5_17, bmats.B_5_18, bmats.B_5_19, bmats.Bx11676, bmats.Bx11694, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx12252.data[0][0], 0, sizeof(bmats.Bx12252.data[0][0])*bmats.Bx12252.shape[0]*bmats.Bx12252.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12252, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
