#include "stdafx.h"
#include "fBx9624.h"

inline int fBx9624(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx9317, bmats.Bx9464, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx9624.data[0][0], 0, sizeof(bmats.Bx9624.data[0][0])*bmats.Bx9624.shape[0]*bmats.Bx9624.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9624, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
