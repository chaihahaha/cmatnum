#include "stdafx.h"
#include "fBx11632.h"

inline int fBx11632(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_29_22, bmats.B_29_25, bmats.B_29_26, bmats.Bx11631, bmats.Bx3046, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx11632.data[0][0], 0, sizeof(bmats.Bx11632.data[0][0])*bmats.Bx11632.shape[0]*bmats.Bx11632.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11632, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
