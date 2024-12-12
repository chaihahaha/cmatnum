#include "stdafx.h"
#include "fBx13313.h"

inline int fBx13313(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_15_2, bmats.B_2_15, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx13313.data[0][0], 0, sizeof(bmats.Bx13313.data[0][0])*bmats.Bx13313.shape[0]*bmats.Bx13313.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13313, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
