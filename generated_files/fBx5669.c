#include "stdafx.h"
#include "fBx5669.h"

inline int fBx5669(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_2_27, bmats.B_32_18, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx5669.data[0][0], 0, sizeof(bmats.Bx5669.data[0][0])*bmats.Bx5669.shape[0]*bmats.Bx5669.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5669, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
