#include "stdafx.h"
#include "fBx4622.h"

inline int fBx4622(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.B_29_17, bmats.B_29_18, bmats.B_29_19, bmats.B_29_20, bmats.B_29_21, bmats.B_29_22, bmats.B_29_23, bmats.B_29_24, bmats.B_29_25, bmats.B_29_26, };
    double B_coeffs[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx4622.data[0][0], 0, sizeof(bmats.Bx4622.data[0][0])*bmats.Bx4622.shape[0]*bmats.Bx4622.shape[1]);
    matlincomb_double_contiguous(bmats.Bx4622, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
