#include "stdafx.h"
#include "fBx6226.h"

inline int fBx6226(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_27_25, bmats.B_27_26, bmats.B_27_31, bmats.B_27_32, bmats.Bx4912, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx6226.data[0][0], 0, sizeof(bmats.Bx6226.data[0][0])*bmats.Bx6226.shape[0]*bmats.Bx6226.shape[1]);
    matlincomb_double_contiguous(bmats.Bx6226, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
