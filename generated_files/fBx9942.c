#include "stdafx.h"
#include "fBx9942.h"

inline int fBx9942(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_18_24, bmats.B_21_2, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx9942.data[0][0], 0, sizeof(bmats.Bx9942.data[0][0])*bmats.Bx9942.shape[0]*bmats.Bx9942.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9942, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}