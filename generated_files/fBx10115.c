#include "stdafx.h"
#include "fBx10115.h"

inline int fBx10115(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_1, bmats.B_17_24, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx10115.data[0][0], 0, sizeof(bmats.Bx10115.data[0][0])*bmats.Bx10115.shape[0]*bmats.Bx10115.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10115, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
