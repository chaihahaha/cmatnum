#include "stdafx.h"
#include "fBx6487.h"

inline int fBx6487(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_24_2, bmats.B_2_27, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx6487.data[0][0], 0, sizeof(bmats.Bx6487.data[0][0])*bmats.Bx6487.shape[0]*bmats.Bx6487.shape[1]);
    matlincomb_double_contiguous(bmats.Bx6487, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}