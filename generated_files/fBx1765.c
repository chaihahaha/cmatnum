#include "stdafx.h"
#include "fBx1765.h"

inline int fBx1765(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_30, bmats.B_20_1, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx1765.data[0][0], 0, sizeof(bmats.Bx1765.data[0][0])*bmats.Bx1765.shape[0]*bmats.Bx1765.shape[1]);
    matlincomb_double_contiguous(bmats.Bx1765, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
