#include "stdafx.h"
#include "fBx12756.h"

inline int fBx12756(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_18_18, bmats.B_25_18, bmats.Bx12686, bmats.Bx12755, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx12756.data[0][0], 0, sizeof(bmats.Bx12756.data[0][0])*bmats.Bx12756.shape[0]*bmats.Bx12756.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12756, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
