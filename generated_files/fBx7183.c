#include "stdafx.h"
#include "fBx7183.h"

inline int fBx7183(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_7_26, bmats.B_8_26, bmats.B_9_26, bmats.Bx7182, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx7183.data[0][0], 0, sizeof(bmats.Bx7183.data[0][0])*bmats.Bx7183.shape[0]*bmats.Bx7183.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7183, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
