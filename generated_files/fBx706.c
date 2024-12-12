#include "stdafx.h"
#include "fBx706.h"

inline int fBx706(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_25_30, bmats.B_30_25, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx706.data[0][0], 0, sizeof(bmats.Bx706.data[0][0])*bmats.Bx706.shape[0]*bmats.Bx706.shape[1]);
    matlincomb_double_contiguous(bmats.Bx706, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
