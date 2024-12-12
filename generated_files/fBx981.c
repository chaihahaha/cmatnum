#include "stdafx.h"
#include "fBx981.h"

inline int fBx981(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_32_25, bmats.B_9_30, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx981.data[0][0], 0, sizeof(bmats.Bx981.data[0][0])*bmats.Bx981.shape[0]*bmats.Bx981.shape[1]);
    matlincomb_double_contiguous(bmats.Bx981, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
