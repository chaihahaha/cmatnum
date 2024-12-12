#include "stdafx.h"
#include "fBx3297.h"

inline int fBx3297(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_25_3, bmats.B_3_29, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx3297.data[0][0], 0, sizeof(bmats.Bx3297.data[0][0])*bmats.Bx3297.shape[0]*bmats.Bx3297.shape[1]);
    matlincomb_double_contiguous(bmats.Bx3297, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
