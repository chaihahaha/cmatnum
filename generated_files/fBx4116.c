#include "stdafx.h"
#include "fBx4116.h"

inline int fBx4116(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_4_25, bmats.B_9_13, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx4116.data[0][0], 0, sizeof(bmats.Bx4116.data[0][0])*bmats.Bx4116.shape[0]*bmats.Bx4116.shape[1]);
    matlincomb_double_contiguous(bmats.Bx4116, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
