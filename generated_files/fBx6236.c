#include "stdafx.h"
#include "fBx6236.h"

inline int fBx6236(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_27_10, bmats.B_27_11, bmats.B_27_15, bmats.B_27_16, bmats.Bx4926, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx6236.data[0][0], 0, sizeof(bmats.Bx6236.data[0][0])*bmats.Bx6236.shape[0]*bmats.Bx6236.shape[1]);
    matlincomb_double_contiguous(bmats.Bx6236, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
