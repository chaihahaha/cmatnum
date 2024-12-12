#include "stdafx.h"
#include "fBx12891.h"

inline int fBx12891(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_4_1, bmats.B_5_1, bmats.B_6_1, bmats.B_7_1, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx12891.data[0][0], 0, sizeof(bmats.Bx12891.data[0][0])*bmats.Bx12891.shape[0]*bmats.Bx12891.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12891, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
