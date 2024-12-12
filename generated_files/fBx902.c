#include "stdafx.h"
#include "fBx902.h"

inline int fBx902(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_10_30, bmats.B_31_10, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx902.data[0][0], 0, sizeof(bmats.Bx902.data[0][0])*bmats.Bx902.shape[0]*bmats.Bx902.shape[1]);
    matlincomb_double_contiguous(bmats.Bx902, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
