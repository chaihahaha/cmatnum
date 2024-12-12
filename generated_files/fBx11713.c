#include "stdafx.h"
#include "fBx11713.h"

inline int fBx11713(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_6_17, bmats.B_6_18, bmats.B_6_19, bmats.B_6_20, bmats.Bx11216, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx11713.data[0][0], 0, sizeof(bmats.Bx11713.data[0][0])*bmats.Bx11713.shape[0]*bmats.Bx11713.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11713, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
