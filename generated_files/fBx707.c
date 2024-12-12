#include "stdafx.h"
#include "fBx707.h"

inline int fBx707(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_26_30, bmats.B_30_26, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx707.data[0][0], 0, sizeof(bmats.Bx707.data[0][0])*bmats.Bx707.shape[0]*bmats.Bx707.shape[1]);
    matlincomb_double_contiguous(bmats.Bx707, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
