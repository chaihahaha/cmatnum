#include "stdafx.h"
#include "fBx12896.h"

inline int fBx12896(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_15_32, bmats.B_32_1, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12896.data[0][0], 0, sizeof(bmats.Bx12896.data[0][0])*bmats.Bx12896.shape[0]*bmats.Bx12896.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12896, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}