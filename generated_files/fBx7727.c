#include "stdafx.h"
#include "fBx7727.h"

inline int fBx7727(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_16_26, bmats.B_20_16, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7727.data[0][0], 0, sizeof(bmats.Bx7727.data[0][0])*bmats.Bx7727.shape[0]*bmats.Bx7727.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7727, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
