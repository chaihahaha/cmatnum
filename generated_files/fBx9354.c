#include "stdafx.h"
#include "fBx9354.h"

inline int fBx9354(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_20, bmats.B_20_25, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx9354.data[0][0], 0, sizeof(bmats.Bx9354.data[0][0])*bmats.Bx9354.shape[0]*bmats.Bx9354.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9354, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
