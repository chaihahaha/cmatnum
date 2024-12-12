#include "stdafx.h"
#include "fBx1981.h"

inline int fBx1981(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_14, bmats.B_6_1, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx1981.data[0][0], 0, sizeof(bmats.Bx1981.data[0][0])*bmats.Bx1981.shape[0]*bmats.Bx1981.shape[1]);
    matlincomb_double_contiguous(bmats.Bx1981, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
