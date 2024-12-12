#include "stdafx.h"
#include "fBx958.h"

inline int fBx958(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_16_8, bmats.B_24_14, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx958.data[0][0], 0, sizeof(bmats.Bx958.data[0][0])*bmats.Bx958.shape[0]*bmats.Bx958.shape[1]);
    matlincomb_double_contiguous(bmats.Bx958, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
