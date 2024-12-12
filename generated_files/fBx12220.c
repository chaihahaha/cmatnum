#include "stdafx.h"
#include "fBx12220.h"

inline int fBx12220(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_4_20, bmats.B_4_32, bmats.Bx11856, bmats.Bx12219, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx12220.data[0][0], 0, sizeof(bmats.Bx12220.data[0][0])*bmats.Bx12220.shape[0]*bmats.Bx12220.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12220, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
