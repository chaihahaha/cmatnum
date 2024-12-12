#include "stdafx.h"
#include "fBx10438.h"

inline int fBx10438(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_32_23, bmats.Bx10236, bmats.Bx10354, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx10438.data[0][0], 0, sizeof(bmats.Bx10438.data[0][0])*bmats.Bx10438.shape[0]*bmats.Bx10438.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10438, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
