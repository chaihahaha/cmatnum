#include "stdafx.h"
#include "fBx5961.h"

inline int fBx5961(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_26_27, bmats.B_31_27, bmats.B_32_27, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx5961.data[0][0], 0, sizeof(bmats.Bx5961.data[0][0])*bmats.Bx5961.shape[0]*bmats.Bx5961.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5961, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
