#include "stdafx.h"
#include "fBx728.h"

inline int fBx728(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_14_13, bmats.B_14_14, bmats.B_14_16, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx728.data[0][0], 0, sizeof(bmats.Bx728.data[0][0])*bmats.Bx728.shape[0]*bmats.Bx728.shape[1]);
    matlincomb_double_contiguous(bmats.Bx728, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
