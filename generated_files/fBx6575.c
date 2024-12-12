#include "stdafx.h"
#include "fBx6575.h"

inline int fBx6575(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_25_5, bmats.B_5_27, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx6575.data[0][0], 0, sizeof(bmats.Bx6575.data[0][0])*bmats.Bx6575.shape[0]*bmats.Bx6575.shape[1]);
    matlincomb_double_contiguous(bmats.Bx6575, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
