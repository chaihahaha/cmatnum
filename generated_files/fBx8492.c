#include "stdafx.h"
#include "fBx8492.h"

inline int fBx8492(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_22, bmats.B_6_26, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx8492.data[0][0], 0, sizeof(bmats.Bx8492.data[0][0])*bmats.Bx8492.shape[0]*bmats.Bx8492.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8492, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}