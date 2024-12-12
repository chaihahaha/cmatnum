#include "stdafx.h"
#include "fBx9003.h"

inline int fBx9003(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_2_9, bmats.B_3_2, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx9003.data[0][0], 0, sizeof(bmats.Bx9003.data[0][0])*bmats.Bx9003.shape[0]*bmats.Bx9003.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9003, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
