#include "stdafx.h"
#include "fBx10045.h"

inline int fBx10045(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_12_7, bmats.B_7_7, bmats.B_8_7, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx10045.data[0][0], 0, sizeof(bmats.Bx10045.data[0][0])*bmats.Bx10045.shape[0]*bmats.Bx10045.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10045, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
