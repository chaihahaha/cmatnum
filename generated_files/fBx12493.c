#include "stdafx.h"
#include "fBx12493.h"

inline int fBx12493(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_10_3, bmats.B_3_3, bmats.Bx12290, bmats.Bx12435, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx12493.data[0][0], 0, sizeof(bmats.Bx12493.data[0][0])*bmats.Bx12493.shape[0]*bmats.Bx12493.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12493, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
