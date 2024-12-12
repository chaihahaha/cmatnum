#include "stdafx.h"
#include "fBx664.h"

inline int fBx664(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_29_2, bmats.B_2_30, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx664.data[0][0], 0, sizeof(bmats.Bx664.data[0][0])*bmats.Bx664.shape[0]*bmats.Bx664.shape[1]);
    matlincomb_double_contiguous(bmats.Bx664, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
