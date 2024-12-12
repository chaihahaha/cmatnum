#include "stdafx.h"
#include "fBx271.h"

inline int fBx271(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_16_31, bmats.B_31_14, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx271.data[0][0], 0, sizeof(bmats.Bx271.data[0][0])*bmats.Bx271.shape[0]*bmats.Bx271.shape[1]);
    matlincomb_double_contiguous(bmats.Bx271, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
