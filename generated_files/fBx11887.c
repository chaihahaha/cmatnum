#include "stdafx.h"
#include "fBx11887.h"

inline int fBx11887(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_21_22, bmats.B_21_32, bmats.Bx11128, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx11887.data[0][0], 0, sizeof(bmats.Bx11887.data[0][0])*bmats.Bx11887.shape[0]*bmats.Bx11887.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11887, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
