#include "stdafx.h"
#include "fBx7950.h"

inline int fBx7950(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_24_10, bmats.B_7_8, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7950.data[0][0], 0, sizeof(bmats.Bx7950.data[0][0])*bmats.Bx7950.shape[0]*bmats.Bx7950.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7950, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
