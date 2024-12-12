#include "stdafx.h"
#include "fBx5595.h"

inline int fBx5595(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_19_12, bmats.B_5_19, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx5595.data[0][0], 0, sizeof(bmats.Bx5595.data[0][0])*bmats.Bx5595.shape[0]*bmats.Bx5595.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5595, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
