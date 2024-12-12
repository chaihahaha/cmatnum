#include "stdafx.h"
#include "fBx668.h"

inline int fBx668(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_13_26, bmats.B_26_14, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx668.data[0][0], 0, sizeof(bmats.Bx668.data[0][0])*bmats.Bx668.shape[0]*bmats.Bx668.shape[1]);
    matlincomb_double_contiguous(bmats.Bx668, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
