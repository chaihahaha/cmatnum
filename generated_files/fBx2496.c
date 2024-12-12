#include "stdafx.h"
#include "fBx2496.h"

inline int fBx2496(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.B_14_18, bmats.B_14_19, bmats.B_14_20, bmats.B_14_21, bmats.B_14_22, bmats.B_14_23, bmats.B_14_24, bmats.B_14_25, bmats.B_14_26, bmats.B_14_27, bmats.B_14_28, bmats.B_14_29, bmats.B_14_30, bmats.B_14_31, bmats.B_14_32, };
    double B_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx2496.data[0][0], 0, sizeof(bmats.Bx2496.data[0][0])*bmats.Bx2496.shape[0]*bmats.Bx2496.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2496, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
