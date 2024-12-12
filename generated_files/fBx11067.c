#include "stdafx.h"
#include "fBx11067.h"

inline int fBx11067(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx10398, bmats.Bx11066, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11067.data[0][0], 0, sizeof(bmats.Bx11067.data[0][0])*bmats.Bx11067.shape[0]*bmats.Bx11067.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11067, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
