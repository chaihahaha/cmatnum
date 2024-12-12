#include "stdafx.h"
#include "fBx11074.h"

inline int fBx11074(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_11_6, bmats.Bx11030, bmats.Bx11045, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx11074.data[0][0], 0, sizeof(bmats.Bx11074.data[0][0])*bmats.Bx11074.shape[0]*bmats.Bx11074.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11074, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
