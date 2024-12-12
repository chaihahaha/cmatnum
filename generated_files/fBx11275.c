#include "stdafx.h"
#include "fBx11275.h"

inline int fBx11275(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_2_8, bmats.Bx8027, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11275.data[0][0], 0, sizeof(bmats.Bx11275.data[0][0])*bmats.Bx11275.shape[0]*bmats.Bx11275.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11275, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
