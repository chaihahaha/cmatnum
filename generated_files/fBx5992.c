#include "stdafx.h"
#include "fBx5992.h"

inline int fBx5992(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_30_25, bmats.B_30_28, bmats.Bx2482, bmats.Bx4653, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx5992.data[0][0], 0, sizeof(bmats.Bx5992.data[0][0])*bmats.Bx5992.shape[0]*bmats.Bx5992.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5992, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
