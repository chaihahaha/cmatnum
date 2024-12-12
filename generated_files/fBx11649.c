#include "stdafx.h"
#include "fBx11649.h"

inline int fBx11649(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_25_17, bmats.B_29_21, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11649.data[0][0], 0, sizeof(bmats.Bx11649.data[0][0])*bmats.Bx11649.shape[0]*bmats.Bx11649.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11649, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
