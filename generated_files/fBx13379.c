#include "stdafx.h"
#include "fBx13379.h"

inline int fBx13379(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_27_32, bmats.B_29_31, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx13379.data[0][0], 0, sizeof(bmats.Bx13379.data[0][0])*bmats.Bx13379.shape[0]*bmats.Bx13379.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13379, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
