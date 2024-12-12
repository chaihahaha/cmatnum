#include "stdafx.h"
#include "fBx11801.h"

inline int fBx11801(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_15_21, bmats.B_19_15, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11801.data[0][0], 0, sizeof(bmats.Bx11801.data[0][0])*bmats.Bx11801.shape[0]*bmats.Bx11801.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11801, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
