#include "stdafx.h"
#include "fBx4046.h"

inline int fBx4046(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_4_9, bmats.B_9_13, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx4046.data[0][0], 0, sizeof(bmats.Bx4046.data[0][0])*bmats.Bx4046.shape[0]*bmats.Bx4046.shape[1]);
    matlincomb_double_contiguous(bmats.Bx4046, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}