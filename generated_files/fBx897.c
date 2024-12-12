#include "stdafx.h"
#include "fBx897.h"

inline int fBx897(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_16_30, bmats.B_31_16, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx897.data[0][0], 0, sizeof(bmats.Bx897.data[0][0])*bmats.Bx897.shape[0]*bmats.Bx897.shape[1]);
    matlincomb_double_contiguous(bmats.Bx897, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
