#include "stdafx.h"
#include "fBx237.h"

inline int fBx237(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_16_22, bmats.B_6_14, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx237.data[0][0], 0, sizeof(bmats.Bx237.data[0][0])*bmats.Bx237.shape[0]*bmats.Bx237.shape[1]);
    matlincomb_double_contiguous(bmats.Bx237, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
