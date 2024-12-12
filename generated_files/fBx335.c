#include "stdafx.h"
#include "fBx335.h"

inline int fBx335(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_22, bmats.B_6_31, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx335.data[0][0], 0, sizeof(bmats.Bx335.data[0][0])*bmats.Bx335.shape[0]*bmats.Bx335.shape[1]);
    matlincomb_double_contiguous(bmats.Bx335, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
