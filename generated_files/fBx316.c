#include "stdafx.h"
#include "fBx316.h"

inline int fBx316(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_1_16, bmats.B_32_15, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx316.data[0][0], 0, sizeof(bmats.Bx316.data[0][0])*bmats.Bx316.shape[0]*bmats.Bx316.shape[1]);
    matlincomb_double_contiguous(bmats.Bx316, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
