#include "stdafx.h"
#include "fBx5962.h"

inline int fBx5962(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 8;
    double_cmat B_mats[8] = {bmats.B_20_27, bmats.B_21_27, bmats.B_22_27, bmats.B_23_27, bmats.B_24_27, bmats.B_25_27, bmats.Bx5960, bmats.Bx5961, };
    double B_coeffs[8] = {1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx5962.data[0][0], 0, sizeof(bmats.Bx5962.data[0][0])*bmats.Bx5962.shape[0]*bmats.Bx5962.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5962, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
