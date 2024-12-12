#include "stdafx.h"
#include "fBx12940.h"

inline int fBx12940(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 12;
    double_cmat B_mats[12] = {bmats.B_10_17, bmats.B_11_17, bmats.B_15_17, bmats.B_16_17, bmats.B_3_17, bmats.B_4_17, bmats.B_5_17, bmats.B_6_17, bmats.B_7_17, bmats.B_8_17, bmats.B_9_17, bmats.Bx12862, };
    double B_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx12940.data[0][0], 0, sizeof(bmats.Bx12940.data[0][0])*bmats.Bx12940.shape[0]*bmats.Bx12940.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12940, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
