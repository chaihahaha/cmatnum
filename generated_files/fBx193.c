#include "stdafx.h"
#include "fBx193.h"

inline int fBx193(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_18_25, bmats.B_20_18, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx193.data[0][0], 0, sizeof(bmats.Bx193.data[0][0])*bmats.Bx193.shape[0]*bmats.Bx193.shape[1]);
    matlincomb_double_contiguous(bmats.Bx193, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}