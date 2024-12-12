#include "stdafx.h"
#include "fBx9993.h"

inline int fBx9993(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_32_24, bmats.Bx9269, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx9993.data[0][0], 0, sizeof(bmats.Bx9993.data[0][0])*bmats.Bx9993.shape[0]*bmats.Bx9993.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9993, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
