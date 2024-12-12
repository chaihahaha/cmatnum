#include "stdafx.h"
#include "fBx2597.h"

inline int fBx2597(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_15_18, bmats.Bx2596, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx2597.data[0][0], 0, sizeof(bmats.Bx2597.data[0][0])*bmats.Bx2597.shape[0]*bmats.Bx2597.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2597, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
