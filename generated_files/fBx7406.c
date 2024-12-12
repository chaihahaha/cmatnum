#include "stdafx.h"
#include "fBx7406.h"

inline int fBx7406(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_4_10, bmats.B_7_10, bmats.Bx7207, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx7406.data[0][0], 0, sizeof(bmats.Bx7406.data[0][0])*bmats.Bx7406.shape[0]*bmats.Bx7406.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7406, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
