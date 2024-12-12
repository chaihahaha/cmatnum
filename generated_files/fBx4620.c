#include "stdafx.h"
#include "fBx4620.h"

inline int fBx4620(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 7;
    double_cmat B_mats[7] = {bmats.B_15_12, bmats.B_4_12, bmats.B_6_12, bmats.B_7_12, bmats.B_9_12, bmats.Bx4618, bmats.Bx4619, };
    double B_coeffs[7] = {1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx4620.data[0][0], 0, sizeof(bmats.Bx4620.data[0][0])*bmats.Bx4620.shape[0]*bmats.Bx4620.shape[1]);
    matlincomb_double_contiguous(bmats.Bx4620, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
