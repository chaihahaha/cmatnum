#include "stdafx.h"
#include "fBx7462.h"

inline int fBx7462(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_7_26, bmats.Bx6380, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7462.data[0][0], 0, sizeof(bmats.Bx7462.data[0][0])*bmats.Bx7462.shape[0]*bmats.Bx7462.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7462, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
