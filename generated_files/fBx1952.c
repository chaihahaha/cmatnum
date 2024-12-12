#include "stdafx.h"
#include "fBx1952.h"

inline int fBx1952(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_6_12, bmats.B_6_5, bmats.B_6_6, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx1952.data[0][0], 0, sizeof(bmats.Bx1952.data[0][0])*bmats.Bx1952.shape[0]*bmats.Bx1952.shape[1]);
    matlincomb_double_contiguous(bmats.Bx1952, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
