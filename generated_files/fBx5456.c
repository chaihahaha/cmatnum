#include "stdafx.h"
#include "fBx5456.h"

inline int fBx5456(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_20_8, bmats.B_24_28, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx5456.data[0][0], 0, sizeof(bmats.Bx5456.data[0][0])*bmats.Bx5456.shape[0]*bmats.Bx5456.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5456, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
