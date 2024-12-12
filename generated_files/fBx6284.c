#include "stdafx.h"
#include "fBx6284.h"

inline int fBx6284(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_28_17, bmats.B_28_19, bmats.B_28_20, bmats.B_28_21, bmats.B_28_22, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx6284.data[0][0], 0, sizeof(bmats.Bx6284.data[0][0])*bmats.Bx6284.shape[0]*bmats.Bx6284.shape[1]);
    matlincomb_double_contiguous(bmats.Bx6284, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
