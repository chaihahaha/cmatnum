#include "stdafx.h"
#include "fBx9722.h"

inline int fBx9722(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_24_15, bmats.B_24_16, bmats.B_24_6, bmats.B_24_7, bmats.B_24_8, bmats.Bx8548, };
    double B_coeffs[6] = {1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx9722.data[0][0], 0, sizeof(bmats.Bx9722.data[0][0])*bmats.Bx9722.shape[0]*bmats.Bx9722.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9722, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
