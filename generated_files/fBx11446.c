#include "stdafx.h"
#include "fBx11446.h"

inline int fBx11446(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_4_21, bmats.Bx11444, bmats.Bx11445, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx11446.data[0][0], 0, sizeof(bmats.Bx11446.data[0][0])*bmats.Bx11446.shape[0]*bmats.Bx11446.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11446, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
