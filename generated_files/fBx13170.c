#include "stdafx.h"
#include "fBx13170.h"

inline int fBx13170(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_14_16, bmats.B_16_14, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx13170.data[0][0], 0, sizeof(bmats.Bx13170.data[0][0])*bmats.Bx13170.shape[0]*bmats.Bx13170.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13170, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}