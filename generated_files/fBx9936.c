#include "stdafx.h"
#include "fBx9936.h"

inline int fBx9936(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_21_16, bmats.B_32_24, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx9936.data[0][0], 0, sizeof(bmats.Bx9936.data[0][0])*bmats.Bx9936.shape[0]*bmats.Bx9936.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9936, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
