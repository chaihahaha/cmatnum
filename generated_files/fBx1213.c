#include "stdafx.h"
#include "fBx1213.h"

inline int fBx1213(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_12_12, bmats.B_12_14, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx1213.data[0][0], 0, sizeof(bmats.Bx1213.data[0][0])*bmats.Bx1213.shape[0]*bmats.Bx1213.shape[1]);
    matlincomb_double_contiguous(bmats.Bx1213, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
