#include "stdafx.h"
#include "fBx12086.h"

inline int fBx12086(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_31_20, bmats.B_32_20, bmats.Bx11894, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx12086.data[0][0], 0, sizeof(bmats.Bx12086.data[0][0])*bmats.Bx12086.shape[0]*bmats.Bx12086.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12086, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
