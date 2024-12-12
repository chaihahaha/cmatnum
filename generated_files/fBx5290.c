#include "stdafx.h"
#include "fBx5290.h"

inline int fBx5290(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_9_3, bmats.B_9_5, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx5290.data[0][0], 0, sizeof(bmats.Bx5290.data[0][0])*bmats.Bx5290.shape[0]*bmats.Bx5290.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5290, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
