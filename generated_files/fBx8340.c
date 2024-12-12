#include "stdafx.h"
#include "fBx8340.h"

inline int fBx8340(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx6050, bmats.Bx8339, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx8340.data[0][0], 0, sizeof(bmats.Bx8340.data[0][0])*bmats.Bx8340.shape[0]*bmats.Bx8340.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8340, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
