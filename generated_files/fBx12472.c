#include "stdafx.h"
#include "fBx12472.h"

inline int fBx12472(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 11;
    double_cmat B_mats[11] = {bmats.B_14_19, bmats.B_15_19, bmats.B_16_19, bmats.B_4_19, bmats.B_5_19, bmats.B_6_19, bmats.B_7_19, bmats.B_8_19, bmats.B_9_19, bmats.Bx12421, bmats.Bx12423, };
    double B_coeffs[11] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx12472.data[0][0], 0, sizeof(bmats.Bx12472.data[0][0])*bmats.Bx12472.shape[0]*bmats.Bx12472.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12472, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
