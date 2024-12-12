#include "stdafx.h"
#include "fBx5791.h"

inline int fBx5791(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_16, bmats.B_32_28, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx5791.data[0][0], 0, sizeof(bmats.Bx5791.data[0][0])*bmats.Bx5791.shape[0]*bmats.Bx5791.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5791, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
