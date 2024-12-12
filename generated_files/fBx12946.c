#include "stdafx.h"
#include "fBx12946.h"

inline int fBx12946(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_10_1, bmats.B_11_1, bmats.B_1_1, bmats.B_2_1, bmats.B_9_1, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx12946.data[0][0], 0, sizeof(bmats.Bx12946.data[0][0])*bmats.Bx12946.shape[0]*bmats.Bx12946.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12946, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
