#include "stdafx.h"
#include "fBx11295.h"

inline int fBx11295(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_16_22, bmats.B_18_32, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11295.data[0][0], 0, sizeof(bmats.Bx11295.data[0][0])*bmats.Bx11295.shape[0]*bmats.Bx11295.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11295, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
