#include "stdafx.h"
#include "fBx13352.h"

inline int fBx13352(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_21_32, bmats.B_22_32, bmats.B_24_32, bmats.Bx13351, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx13352.data[0][0], 0, sizeof(bmats.Bx13352.data[0][0])*bmats.Bx13352.shape[0]*bmats.Bx13352.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13352, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}