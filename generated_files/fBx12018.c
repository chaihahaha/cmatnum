#include "stdafx.h"
#include "fBx12018.h"

inline int fBx12018(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_1_21, bmats.Bx11267, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12018.data[0][0], 0, sizeof(bmats.Bx12018.data[0][0])*bmats.Bx12018.shape[0]*bmats.Bx12018.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12018, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
