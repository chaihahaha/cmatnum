#include "stdafx.h"
#include "fBx9245.h"

inline int fBx9245(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_18_8, bmats.B_26_8, bmats.B_29_8, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx9245.data[0][0], 0, sizeof(bmats.Bx9245.data[0][0])*bmats.Bx9245.shape[0]*bmats.Bx9245.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9245, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
