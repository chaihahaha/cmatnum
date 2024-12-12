#include "stdafx.h"
#include "fBx13366.h"

inline int fBx13366(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_21_32, bmats.B_22_32, bmats.B_23_32, bmats.B_31_32, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx13366.data[0][0], 0, sizeof(bmats.Bx13366.data[0][0])*bmats.Bx13366.shape[0]*bmats.Bx13366.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13366, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
