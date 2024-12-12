#include "stdafx.h"
#include "fBx8328.h"

inline int fBx8328(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_31_26, bmats.Bx7264, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx8328.data[0][0], 0, sizeof(bmats.Bx8328.data[0][0])*bmats.Bx8328.shape[0]*bmats.Bx8328.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8328, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
