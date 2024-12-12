#include "stdafx.h"
#include "fBx414.h"

inline int fBx414(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_11_15, bmats.B_2_11, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx414.data[0][0], 0, sizeof(bmats.Bx414.data[0][0])*bmats.Bx414.shape[0]*bmats.Bx414.shape[1]);
    matlincomb_double_contiguous(bmats.Bx414, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
