#include "stdafx.h"
#include "fBx7707.h"

inline int fBx7707(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_10_19, bmats.B_3_10, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7707.data[0][0], 0, sizeof(bmats.Bx7707.data[0][0])*bmats.Bx7707.shape[0]*bmats.Bx7707.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7707, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
