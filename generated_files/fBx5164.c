#include "stdafx.h"
#include "fBx5164.h"

inline int fBx5164(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_1_28, bmats.B_23_1, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx5164.data[0][0], 0, sizeof(bmats.Bx5164.data[0][0])*bmats.Bx5164.shape[0]*bmats.Bx5164.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5164, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}