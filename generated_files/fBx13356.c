#include "stdafx.h"
#include "fBx13356.h"

inline int fBx13356(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_2_16, bmats.B_3_16, bmats.B_5_16, bmats.Bx13233, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx13356.data[0][0], 0, sizeof(bmats.Bx13356.data[0][0])*bmats.Bx13356.shape[0]*bmats.Bx13356.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13356, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
