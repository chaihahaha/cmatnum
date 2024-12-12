#include "stdafx.h"
#include "fBx733.h"

inline int fBx733(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_2_30, bmats.B_30_18, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx733.data[0][0], 0, sizeof(bmats.Bx733.data[0][0])*bmats.Bx733.shape[0]*bmats.Bx733.shape[1]);
    matlincomb_double_contiguous(bmats.Bx733, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
