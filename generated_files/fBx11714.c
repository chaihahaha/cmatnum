#include "stdafx.h"
#include "fBx11714.h"

inline int fBx11714(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_22_15, bmats.B_22_16, bmats.B_22_5, bmats.B_22_6, bmats.Bx11711, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx11714.data[0][0], 0, sizeof(bmats.Bx11714.data[0][0])*bmats.Bx11714.shape[0]*bmats.Bx11714.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11714, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
