#include "stdafx.h"
#include "fBx6247.h"

inline int fBx6247(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_11_27, bmats.B_11_31, bmats.Bx4940, bmats.Bx6246, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx6247.data[0][0], 0, sizeof(bmats.Bx6247.data[0][0])*bmats.Bx6247.shape[0]*bmats.Bx6247.shape[1]);
    matlincomb_double_contiguous(bmats.Bx6247, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}