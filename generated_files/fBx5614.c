#include "stdafx.h"
#include "fBx5614.h"

inline int fBx5614(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_2_12, bmats.B_6_2, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx5614.data[0][0], 0, sizeof(bmats.Bx5614.data[0][0])*bmats.Bx5614.shape[0]*bmats.Bx5614.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5614, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}