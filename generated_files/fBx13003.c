#include "stdafx.h"
#include "fBx13003.h"

inline int fBx13003(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_25_17, bmats.B_29_17, bmats.B_32_17, bmats.Bx12900, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx13003.data[0][0], 0, sizeof(bmats.Bx13003.data[0][0])*bmats.Bx13003.shape[0]*bmats.Bx13003.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13003, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
