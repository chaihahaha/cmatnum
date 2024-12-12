#include "stdafx.h"
#include "fBx9193.h"

inline int fBx9193(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_10_24, bmats.B_11_24, bmats.B_12_24, bmats.B_13_24, bmats.B_14_24, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx9193.data[0][0], 0, sizeof(bmats.Bx9193.data[0][0])*bmats.Bx9193.shape[0]*bmats.Bx9193.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9193, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
