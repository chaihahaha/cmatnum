#include "stdafx.h"
#include "fBx11434.h"

inline int fBx11434(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_12_5, bmats.B_14_5, bmats.B_9_5, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx11434.data[0][0], 0, sizeof(bmats.Bx11434.data[0][0])*bmats.Bx11434.shape[0]*bmats.Bx11434.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11434, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}