#include "stdafx.h"
#include "fBx12871.h"

inline int fBx12871(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_14_1, bmats.B_16_1, bmats.B_4_1, bmats.B_5_1, bmats.B_6_1, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx12871.data[0][0], 0, sizeof(bmats.Bx12871.data[0][0])*bmats.Bx12871.shape[0]*bmats.Bx12871.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12871, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
