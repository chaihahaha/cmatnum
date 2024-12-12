#include "stdafx.h"
#include "fBx11916.h"

inline int fBx11916(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 9;
    double_cmat B_mats[9] = {bmats.B_10_20, bmats.B_11_20, bmats.B_12_20, bmats.B_13_20, bmats.B_14_20, bmats.B_5_20, bmats.B_6_20, bmats.B_7_20, bmats.B_8_20, };
    double B_coeffs[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx11916.data[0][0], 0, sizeof(bmats.Bx11916.data[0][0])*bmats.Bx11916.shape[0]*bmats.Bx11916.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11916, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
