#include "stdafx.h"
#include "fBx931.h"

inline int fBx931(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_16_5, bmats.B_5_14, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx931.data[0][0], 0, sizeof(bmats.Bx931.data[0][0])*bmats.Bx931.shape[0]*bmats.Bx931.shape[1]);
    matlincomb_double_contiguous(bmats.Bx931, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
