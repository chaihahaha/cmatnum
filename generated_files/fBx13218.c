#include "stdafx.h"
#include "fBx13218.h"

inline int fBx13218(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.B_16_15, bmats.B_1_15, bmats.B_2_15, bmats.B_3_15, bmats.B_4_15, bmats.B_5_15, bmats.B_6_15, bmats.B_7_15, bmats.Bx299, bmats.Bx551, };
    double B_coeffs[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx13218.data[0][0], 0, sizeof(bmats.Bx13218.data[0][0])*bmats.Bx13218.shape[0]*bmats.Bx13218.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13218, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
