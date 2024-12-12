#include "stdafx.h"
#include "fBx12111.h"

inline int fBx12111(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 8;
    double_cmat B_mats[8] = {bmats.B_10_20, bmats.B_11_20, bmats.B_12_20, bmats.B_14_20, bmats.B_5_20, bmats.B_7_20, bmats.B_8_20, bmats.B_9_20, };
    double B_coeffs[8] = {1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx12111.data[0][0], 0, sizeof(bmats.Bx12111.data[0][0])*bmats.Bx12111.shape[0]*bmats.Bx12111.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12111, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
