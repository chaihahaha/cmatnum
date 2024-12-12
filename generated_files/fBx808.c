#include "stdafx.h"
#include "fBx808.h"

inline int fBx808(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_14_29, bmats.B_17_14, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx808.data[0][0], 0, sizeof(bmats.Bx808.data[0][0])*bmats.Bx808.shape[0]*bmats.Bx808.shape[1]);
    matlincomb_double_contiguous(bmats.Bx808, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
