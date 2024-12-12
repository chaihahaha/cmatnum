#include "stdafx.h"
#include "fBx895.h"

inline int fBx895(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_15_17, bmats.B_15_19, bmats.B_15_30, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx895.data[0][0], 0, sizeof(bmats.Bx895.data[0][0])*bmats.Bx895.shape[0]*bmats.Bx895.shape[1]);
    matlincomb_double_contiguous(bmats.Bx895, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
