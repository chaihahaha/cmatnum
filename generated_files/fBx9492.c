#include "stdafx.h"
#include "fBx9492.h"

inline int fBx9492(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_17_24, bmats.Bx9210, bmats.Bx9480, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx9492.data[0][0], 0, sizeof(bmats.Bx9492.data[0][0])*bmats.Bx9492.shape[0]*bmats.Bx9492.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9492, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}