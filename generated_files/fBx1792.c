#include "stdafx.h"
#include "fBx1792.h"

inline int fBx1792(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_20_8, bmats.B_8_30, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx1792.data[0][0], 0, sizeof(bmats.Bx1792.data[0][0])*bmats.Bx1792.shape[0]*bmats.Bx1792.shape[1]);
    matlincomb_double_contiguous(bmats.Bx1792, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
