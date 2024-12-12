#include "stdafx.h"
#include "fBx551.h"

inline int fBx551(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_10_15, bmats.B_13_15, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx551.data[0][0], 0, sizeof(bmats.Bx551.data[0][0])*bmats.Bx551.shape[0]*bmats.Bx551.shape[1]);
    matlincomb_double_contiguous(bmats.Bx551, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
