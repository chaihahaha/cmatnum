#include "stdafx.h"
#include "fBx4177.h"

inline int fBx4177(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_21_28, bmats.B_28_29, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx4177.data[0][0], 0, sizeof(bmats.Bx4177.data[0][0])*bmats.Bx4177.shape[0]*bmats.Bx4177.shape[1]);
    matlincomb_double_contiguous(bmats.Bx4177, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}