#include "stdafx.h"
#include "fBx903.h"

inline int fBx903(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_31_9, bmats.B_9_30, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx903.data[0][0], 0, sizeof(bmats.Bx903.data[0][0])*bmats.Bx903.shape[0]*bmats.Bx903.shape[1]);
    matlincomb_double_contiguous(bmats.Bx903, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
