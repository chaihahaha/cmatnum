#include "stdafx.h"
#include "fBx9623.h"

inline int fBx9623(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx2072, bmats.Bx9622, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx9623.data[0][0], 0, sizeof(bmats.Bx9623.data[0][0])*bmats.Bx9623.shape[0]*bmats.Bx9623.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9623, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
