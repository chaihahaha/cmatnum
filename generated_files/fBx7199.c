#include "stdafx.h"
#include "fBx7199.h"

inline int fBx7199(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_10_10, bmats.B_11_10, bmats.B_12_10, bmats.B_7_10, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx7199.data[0][0], 0, sizeof(bmats.Bx7199.data[0][0])*bmats.Bx7199.shape[0]*bmats.Bx7199.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7199, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
