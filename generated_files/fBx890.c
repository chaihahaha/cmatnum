#include "stdafx.h"
#include "fBx890.h"

inline int fBx890(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_12_14, bmats.B_15_28, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx890.data[0][0], 0, sizeof(bmats.Bx890.data[0][0])*bmats.Bx890.shape[0]*bmats.Bx890.shape[1]);
    matlincomb_double_contiguous(bmats.Bx890, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
