#include "stdafx.h"
#include "fBx874.h"

inline int fBx874(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_27_30, bmats.B_31_11, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx874.data[0][0], 0, sizeof(bmats.Bx874.data[0][0])*bmats.Bx874.shape[0]*bmats.Bx874.shape[1]);
    matlincomb_double_contiguous(bmats.Bx874, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
