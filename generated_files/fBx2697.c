#include "stdafx.h"
#include "fBx2697.h"

inline int fBx2697(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_16_19, bmats.B_3_13, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx2697.data[0][0], 0, sizeof(bmats.Bx2697.data[0][0])*bmats.Bx2697.shape[0]*bmats.Bx2697.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2697, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
