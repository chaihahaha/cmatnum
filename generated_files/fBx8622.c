#include "stdafx.h"
#include "fBx8622.h"

inline int fBx8622(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_25_15, bmats.B_25_16, bmats.B_25_9, bmats.Bx7628, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx8622.data[0][0], 0, sizeof(bmats.Bx8622.data[0][0])*bmats.Bx8622.shape[0]*bmats.Bx8622.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8622, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
