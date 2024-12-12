#include "stdafx.h"
#include "fBx11724.h"

inline int fBx11724(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_24_18, bmats.Bx9716, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11724.data[0][0], 0, sizeof(bmats.Bx11724.data[0][0])*bmats.Bx11724.shape[0]*bmats.Bx11724.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11724, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
