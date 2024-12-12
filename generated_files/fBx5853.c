#include "stdafx.h"
#include "fBx5853.h"

inline int fBx5853(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 1;
    double_cmat B_mats[1] = {bmats.B_28_18, };
    double B_coeffs[1] = {-1, };
memset(&bmats.Bx5853.data[0][0], 0, sizeof(bmats.Bx5853.data[0][0])*bmats.Bx5853.shape[0]*bmats.Bx5853.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5853, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
