#include "stdafx.h"
#include "fBx823.h"

inline int fBx823(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_16_14, bmats.B_8_14, bmats.Bx822, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx823.data[0][0], 0, sizeof(bmats.Bx823.data[0][0])*bmats.Bx823.shape[0]*bmats.Bx823.shape[1]);
    matlincomb_double_contiguous(bmats.Bx823, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}