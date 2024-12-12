#include "stdafx.h"
#include "fBx11903.h"

inline int fBx11903(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_10_4, bmats.B_11_4, bmats.B_12_4, bmats.B_4_4, bmats.B_7_4, bmats.B_8_4, };
    double B_coeffs[6] = {1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx11903.data[0][0], 0, sizeof(bmats.Bx11903.data[0][0])*bmats.Bx11903.shape[0]*bmats.Bx11903.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11903, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
