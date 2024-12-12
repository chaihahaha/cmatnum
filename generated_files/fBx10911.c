#include "stdafx.h"
#include "fBx10911.h"

inline int fBx10911(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_4_22, bmats.B_5_22, bmats.Bx10910, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx10911.data[0][0], 0, sizeof(bmats.Bx10911.data[0][0])*bmats.Bx10911.shape[0]*bmats.Bx10911.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10911, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
