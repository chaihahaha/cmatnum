#include "stdafx.h"
#include "fBx13025.h"

inline int fBx13025(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_16_1, bmats.B_5_16, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx13025.data[0][0], 0, sizeof(bmats.Bx13025.data[0][0])*bmats.Bx13025.shape[0]*bmats.Bx13025.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13025, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
