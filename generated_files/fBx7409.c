#include "stdafx.h"
#include "fBx7409.h"

inline int fBx7409(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_11_1, bmats.B_11_4, bmats.B_11_5, bmats.B_11_9, bmats.Bx1091, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx7409.data[0][0], 0, sizeof(bmats.Bx7409.data[0][0])*bmats.Bx7409.shape[0]*bmats.Bx7409.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7409, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}