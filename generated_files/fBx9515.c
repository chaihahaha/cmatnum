#include "stdafx.h"
#include "fBx9515.h"

inline int fBx9515(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_15_15, bmats.Bx9500, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx9515.data[0][0], 0, sizeof(bmats.Bx9515.data[0][0])*bmats.Bx9515.shape[0]*bmats.Bx9515.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9515, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}