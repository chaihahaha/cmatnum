#include "stdafx.h"
#include "fBx4658.h"

inline int fBx4658(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_15_6, bmats.B_6_12, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx4658.data[0][0], 0, sizeof(bmats.Bx4658.data[0][0])*bmats.Bx4658.shape[0]*bmats.Bx4658.shape[1]);
    matlincomb_double_contiguous(bmats.Bx4658, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}