#include "stdafx.h"
#include "fBx10246.h"

inline int fBx10246(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_5_23, bmats.B_6_23, bmats.Bx10242, bmats.Bx10244, bmats.Bx10245, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx10246.data[0][0], 0, sizeof(bmats.Bx10246.data[0][0])*bmats.Bx10246.shape[0]*bmats.Bx10246.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10246, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
