#include "stdafx.h"
#include "fBx11473.h"

inline int fBx11473(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx11450, bmats.Bx11472, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11473.data[0][0], 0, sizeof(bmats.Bx11473.data[0][0])*bmats.Bx11473.shape[0]*bmats.Bx11473.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11473, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}