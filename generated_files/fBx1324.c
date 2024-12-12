#include "stdafx.h"
#include "fBx1324.h"

inline int fBx1324(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_13_15, bmats.B_31_14, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx1324.data[0][0], 0, sizeof(bmats.Bx1324.data[0][0])*bmats.Bx1324.shape[0]*bmats.Bx1324.shape[1]);
    matlincomb_double_contiguous(bmats.Bx1324, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
