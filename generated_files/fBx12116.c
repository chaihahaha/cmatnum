#include "stdafx.h"
#include "fBx12116.h"

inline int fBx12116(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_26_19, bmats.B_30_20, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12116.data[0][0], 0, sizeof(bmats.Bx12116.data[0][0])*bmats.Bx12116.shape[0]*bmats.Bx12116.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12116, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
