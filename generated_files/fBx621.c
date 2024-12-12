#include "stdafx.h"
#include "fBx621.h"

inline int fBx621(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_2_15, bmats.B_3_18, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx621.data[0][0], 0, sizeof(bmats.Bx621.data[0][0])*bmats.Bx621.shape[0]*bmats.Bx621.shape[1]);
    matlincomb_double_contiguous(bmats.Bx621, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
