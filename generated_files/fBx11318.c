#include "stdafx.h"
#include "fBx11318.h"

inline int fBx11318(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_18_2, bmats.B_2_22, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11318.data[0][0], 0, sizeof(bmats.Bx11318.data[0][0])*bmats.Bx11318.shape[0]*bmats.Bx11318.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11318, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
