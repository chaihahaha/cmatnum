#include "stdafx.h"
#include "fBx1987.h"

inline int fBx1987(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_1_30, bmats.B_22_17, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx1987.data[0][0], 0, sizeof(bmats.Bx1987.data[0][0])*bmats.Bx1987.shape[0]*bmats.Bx1987.shape[1]);
    matlincomb_double_contiguous(bmats.Bx1987, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
