#include "stdafx.h"
#include "fBx9629.h"

inline int fBx9629(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_32_8, bmats.B_7_16, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx9629.data[0][0], 0, sizeof(bmats.Bx9629.data[0][0])*bmats.Bx9629.shape[0]*bmats.Bx9629.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9629, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
