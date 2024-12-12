#include "stdafx.h"
#include "fBx11244.h"

inline int fBx11244(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_7_3, bmats.Bx11243, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11244.data[0][0], 0, sizeof(bmats.Bx11244.data[0][0])*bmats.Bx11244.shape[0]*bmats.Bx11244.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11244, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
