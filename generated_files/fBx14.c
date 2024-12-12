#include "stdafx.h"
#include "fBx14.h"

inline int fBx14(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_20_28, bmats.B_27_20, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx14.data[0][0], 0, sizeof(bmats.Bx14.data[0][0])*bmats.Bx14.shape[0]*bmats.Bx14.shape[1]);
    matlincomb_double_contiguous(bmats.Bx14, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
