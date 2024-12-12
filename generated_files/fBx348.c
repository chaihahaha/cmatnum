#include "stdafx.h"
#include "fBx348.h"

inline int fBx348(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_1_31, bmats.Bx347, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx348.data[0][0], 0, sizeof(bmats.Bx348.data[0][0])*bmats.Bx348.shape[0]*bmats.Bx348.shape[1]);
    matlincomb_double_contiguous(bmats.Bx348, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
