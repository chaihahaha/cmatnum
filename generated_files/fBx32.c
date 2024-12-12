#include "stdafx.h"
#include "fBx32.h"

inline int fBx32(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_19_28, bmats.B_25_19, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx32.data[0][0], 0, sizeof(bmats.Bx32.data[0][0])*bmats.Bx32.shape[0]*bmats.Bx32.shape[1]);
    matlincomb_double_contiguous(bmats.Bx32, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
