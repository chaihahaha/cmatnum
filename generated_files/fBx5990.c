#include "stdafx.h"
#include "fBx5990.h"

inline int fBx5990(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_27_27, bmats.B_29_27, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx5990.data[0][0], 0, sizeof(bmats.Bx5990.data[0][0])*bmats.Bx5990.shape[0]*bmats.Bx5990.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5990, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
