#include "stdafx.h"
#include "fBx4871.h"

inline int fBx4871(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_11_3, bmats.B_3_12, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx4871.data[0][0], 0, sizeof(bmats.Bx4871.data[0][0])*bmats.Bx4871.shape[0]*bmats.Bx4871.shape[1]);
    matlincomb_double_contiguous(bmats.Bx4871, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
