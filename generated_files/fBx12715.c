#include "stdafx.h"
#include "fBx12715.h"

inline int fBx12715(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_16_1, bmats.B_17_2, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12715.data[0][0], 0, sizeof(bmats.Bx12715.data[0][0])*bmats.Bx12715.shape[0]*bmats.Bx12715.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12715, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
