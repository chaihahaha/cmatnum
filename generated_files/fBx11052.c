#include "stdafx.h"
#include "fBx11052.h"

inline int fBx11052(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_28_19, bmats.B_28_20, bmats.B_28_27, bmats.Bx6287, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx11052.data[0][0], 0, sizeof(bmats.Bx11052.data[0][0])*bmats.Bx11052.shape[0]*bmats.Bx11052.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11052, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
