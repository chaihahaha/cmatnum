#include "stdafx.h"
#include "fBx11772.h"

inline int fBx11772(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_31_5, bmats.B_3_15, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11772.data[0][0], 0, sizeof(bmats.Bx11772.data[0][0])*bmats.Bx11772.shape[0]*bmats.Bx11772.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11772, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
