#include "stdafx.h"
#include "fBx116.h"

inline int fBx116(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_24_26, bmats.B_25_24, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx116.data[0][0], 0, sizeof(bmats.Bx116.data[0][0])*bmats.Bx116.shape[0]*bmats.Bx116.shape[1]);
    matlincomb_double_contiguous(bmats.Bx116, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}