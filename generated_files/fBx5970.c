#include "stdafx.h"
#include "fBx5970.h"

inline int fBx5970(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 7;
    double_cmat B_mats[7] = {bmats.B_20_11, bmats.B_21_11, bmats.Bx5964, bmats.Bx5965, bmats.Bx5966, bmats.Bx5968, bmats.Bx5969, };
    double B_coeffs[7] = {1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx5970.data[0][0], 0, sizeof(bmats.Bx5970.data[0][0])*bmats.Bx5970.shape[0]*bmats.Bx5970.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5970, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
