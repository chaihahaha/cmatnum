#include "stdafx.h"
#include "fBx5974.h"

inline int fBx5974(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_15_27, bmats.B_1_27, bmats.B_2_27, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx5974.data[0][0], 0, sizeof(bmats.Bx5974.data[0][0])*bmats.Bx5974.shape[0]*bmats.Bx5974.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5974, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
