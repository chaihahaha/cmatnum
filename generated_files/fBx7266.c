#include "stdafx.h"
#include "fBx7266.h"

inline int fBx7266(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_31_15, bmats.B_31_26, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7266.data[0][0], 0, sizeof(bmats.Bx7266.data[0][0])*bmats.Bx7266.shape[0]*bmats.Bx7266.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7266, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
