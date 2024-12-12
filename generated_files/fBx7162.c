#include "stdafx.h"
#include "fBx7162.h"

inline int fBx7162(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_16_11, bmats.B_3_32, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7162.data[0][0], 0, sizeof(bmats.Bx7162.data[0][0])*bmats.Bx7162.shape[0]*bmats.Bx7162.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7162, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
