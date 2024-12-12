#include "stdafx.h"
#include "fBx451.h"

inline int fBx451(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_23_15, bmats.B_2_7, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx451.data[0][0], 0, sizeof(bmats.Bx451.data[0][0])*bmats.Bx451.shape[0]*bmats.Bx451.shape[1]);
    matlincomb_double_contiguous(bmats.Bx451, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
