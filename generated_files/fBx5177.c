#include "stdafx.h"
#include "fBx5177.h"

inline int fBx5177(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_27_12, bmats.B_7_27, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx5177.data[0][0], 0, sizeof(bmats.Bx5177.data[0][0])*bmats.Bx5177.shape[0]*bmats.Bx5177.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5177, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
