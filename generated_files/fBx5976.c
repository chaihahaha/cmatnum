#include "stdafx.h"
#include "fBx5976.h"

inline int fBx5976(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 8;
    double_cmat B_mats[8] = {bmats.B_3_27, bmats.B_4_27, bmats.B_5_27, bmats.B_6_27, bmats.B_8_27, bmats.Bx5973, bmats.Bx5974, bmats.Bx5975, };
    double B_coeffs[8] = {1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx5976.data[0][0], 0, sizeof(bmats.Bx5976.data[0][0])*bmats.Bx5976.shape[0]*bmats.Bx5976.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5976, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
