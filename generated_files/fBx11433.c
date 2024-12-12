#include "stdafx.h"
#include "fBx11433.h"

inline int fBx11433(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.B_10_5, bmats.B_11_5, bmats.B_13_5, bmats.B_16_5, bmats.B_1_5, bmats.B_2_5, bmats.B_3_5, bmats.B_5_5, bmats.B_6_5, bmats.B_8_5, };
    double B_coeffs[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx11433.data[0][0], 0, sizeof(bmats.Bx11433.data[0][0])*bmats.Bx11433.shape[0]*bmats.Bx11433.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11433, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
