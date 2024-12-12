#include "stdafx.h"
#include "fBx10896.h"

inline int fBx10896(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 7;
    double_cmat B_mats[7] = {bmats.B_22_22, bmats.B_24_22, bmats.B_25_22, bmats.B_26_22, bmats.B_27_22, bmats.B_28_22, bmats.B_29_22, };
    double B_coeffs[7] = {1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx10896.data[0][0], 0, sizeof(bmats.Bx10896.data[0][0])*bmats.Bx10896.shape[0]*bmats.Bx10896.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10896, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
