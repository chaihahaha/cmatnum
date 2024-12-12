#include "stdafx.h"
#include "fBx4605.h"

inline int fBx4605(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_12_20, bmats.B_24_12, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx4605.data[0][0], 0, sizeof(bmats.Bx4605.data[0][0])*bmats.Bx4605.shape[0]*bmats.Bx4605.shape[1]);
    matlincomb_double_contiguous(bmats.Bx4605, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
