#include "stdafx.h"
#include "fBx8276.h"

inline int fBx8276(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_10_25, bmats.B_11_25, bmats.B_14_25, bmats.B_9_25, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx8276.data[0][0], 0, sizeof(bmats.Bx8276.data[0][0])*bmats.Bx8276.shape[0]*bmats.Bx8276.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8276, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
