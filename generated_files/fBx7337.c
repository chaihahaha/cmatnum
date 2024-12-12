#include "stdafx.h"
#include "fBx7337.h"

inline int fBx7337(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_16_2, bmats.B_18_10, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7337.data[0][0], 0, sizeof(bmats.Bx7337.data[0][0])*bmats.Bx7337.shape[0]*bmats.Bx7337.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7337, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
