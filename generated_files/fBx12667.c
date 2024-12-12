#include "stdafx.h"
#include "fBx12667.h"

inline int fBx12667(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.B_19_2, bmats.B_20_2, bmats.B_21_2, bmats.B_22_2, bmats.B_23_2, bmats.B_24_2, bmats.B_25_2, bmats.B_26_2, bmats.B_27_2, bmats.B_28_2, bmats.B_29_2, bmats.B_30_2, bmats.B_31_2, };
    double B_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx12667.data[0][0], 0, sizeof(bmats.Bx12667.data[0][0])*bmats.Bx12667.shape[0]*bmats.Bx12667.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12667, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
