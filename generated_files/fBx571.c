#include "stdafx.h"
#include "fBx571.h"

inline int fBx571(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_29_15, bmats.B_3_13, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx571.data[0][0], 0, sizeof(bmats.Bx571.data[0][0])*bmats.Bx571.shape[0]*bmats.Bx571.shape[1]);
    matlincomb_double_contiguous(bmats.Bx571, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}