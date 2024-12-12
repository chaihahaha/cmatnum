#include "stdafx.h"
#include "fBx6971.h"

inline int fBx6971(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_1_27, bmats.Bx5814, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx6971.data[0][0], 0, sizeof(bmats.Bx6971.data[0][0])*bmats.Bx6971.shape[0]*bmats.Bx6971.shape[1]);
    matlincomb_double_contiguous(bmats.Bx6971, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
