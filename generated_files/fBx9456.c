#include "stdafx.h"
#include "fBx9456.h"

inline int fBx9456(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_15_24, bmats.B_6_24, bmats.B_7_24, bmats.Bx9295, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx9456.data[0][0], 0, sizeof(bmats.Bx9456.data[0][0])*bmats.Bx9456.shape[0]*bmats.Bx9456.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9456, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
