#include "stdafx.h"
#include "fBx8380.h"

inline int fBx8380(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_31_25, bmats.B_32_31, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx8380.data[0][0], 0, sizeof(bmats.Bx8380.data[0][0])*bmats.Bx8380.shape[0]*bmats.Bx8380.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8380, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
