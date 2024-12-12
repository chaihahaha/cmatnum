#include "stdafx.h"
#include "fBx5341.h"

inline int fBx5341(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_19_19, bmats.Bx5340, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx5341.data[0][0], 0, sizeof(bmats.Bx5341.data[0][0])*bmats.Bx5341.shape[0]*bmats.Bx5341.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5341, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
