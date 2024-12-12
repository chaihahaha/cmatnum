#include "stdafx.h"
#include "fBx11658.h"

inline int fBx11658(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_21_21, bmats.B_23_21, bmats.B_24_21, bmats.B_28_21, bmats.B_30_21, bmats.Bx11638, };
    double B_coeffs[6] = {1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx11658.data[0][0], 0, sizeof(bmats.Bx11658.data[0][0])*bmats.Bx11658.shape[0]*bmats.Bx11658.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11658, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
