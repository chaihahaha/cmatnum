#include "stdafx.h"
#include "fBx1059.h"

inline int fBx1059(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_10_14, bmats.B_11_10, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx1059.data[0][0], 0, sizeof(bmats.Bx1059.data[0][0])*bmats.Bx1059.shape[0]*bmats.Bx1059.shape[1]);
    matlincomb_double_contiguous(bmats.Bx1059, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
