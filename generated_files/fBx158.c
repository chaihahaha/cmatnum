#include "stdafx.h"
#include "fBx158.h"

inline int fBx158(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_18_26, bmats.B_20_18, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx158.data[0][0], 0, sizeof(bmats.Bx158.data[0][0])*bmats.Bx158.shape[0]*bmats.Bx158.shape[1]);
    matlincomb_double_contiguous(bmats.Bx158, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}