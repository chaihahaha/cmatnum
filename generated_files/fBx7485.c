#include "stdafx.h"
#include "fBx7485.h"

inline int fBx7485(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_24_10, bmats.B_7_24, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7485.data[0][0], 0, sizeof(bmats.Bx7485.data[0][0])*bmats.Bx7485.shape[0]*bmats.Bx7485.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7485, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
