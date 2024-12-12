#include "stdafx.h"
#include "fBx12793.h"

inline int fBx12793(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 8;
    double_cmat B_mats[8] = {bmats.B_12_18, bmats.B_15_18, bmats.B_3_18, bmats.B_6_18, bmats.B_9_18, bmats.Bx12749, bmats.Bx12778, bmats.Bx12785, };
    double B_coeffs[8] = {1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx12793.data[0][0], 0, sizeof(bmats.Bx12793.data[0][0])*bmats.Bx12793.shape[0]*bmats.Bx12793.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12793, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
