#include "stdafx.h"
#include "fBx4222.h"

inline int fBx4222(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_23_28, bmats.B_31_7, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx4222.data[0][0], 0, sizeof(bmats.Bx4222.data[0][0])*bmats.Bx4222.shape[0]*bmats.Bx4222.shape[1]);
    matlincomb_double_contiguous(bmats.Bx4222, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
