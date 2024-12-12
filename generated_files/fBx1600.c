#include "stdafx.h"
#include "fBx1600.h"

inline int fBx1600(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_9_14, bmats.B_9_9, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx1600.data[0][0], 0, sizeof(bmats.Bx1600.data[0][0])*bmats.Bx1600.shape[0]*bmats.Bx1600.shape[1]);
    matlincomb_double_contiguous(bmats.Bx1600, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
