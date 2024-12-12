#include "stdafx.h"
#include "fBx13188.h"

inline int fBx13188(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_10_15, bmats.B_15_10, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx13188.data[0][0], 0, sizeof(bmats.Bx13188.data[0][0])*bmats.Bx13188.shape[0]*bmats.Bx13188.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13188, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
