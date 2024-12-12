#include "stdafx.h"
#include "fBx8282.h"

inline int fBx8282(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_17_9, bmats.B_18_9, bmats.B_31_9, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx8282.data[0][0], 0, sizeof(bmats.Bx8282.data[0][0])*bmats.Bx8282.shape[0]*bmats.Bx8282.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8282, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
