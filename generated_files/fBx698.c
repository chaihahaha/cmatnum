#include "stdafx.h"
#include "fBx698.h"

inline int fBx698(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_14_6, bmats.B_5_14, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx698.data[0][0], 0, sizeof(bmats.Bx698.data[0][0])*bmats.Bx698.shape[0]*bmats.Bx698.shape[1]);
    matlincomb_double_contiguous(bmats.Bx698, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
