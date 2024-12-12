#include "stdafx.h"
#include "fBx9283.h"

inline int fBx9283(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx9243, bmats.Bx9282, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx9283.data[0][0], 0, sizeof(bmats.Bx9283.data[0][0])*bmats.Bx9283.shape[0]*bmats.Bx9283.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9283, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
