#include "stdafx.h"
#include "fBx822.h"

inline int fBx822(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_14_14, bmats.B_3_14, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx822.data[0][0], 0, sizeof(bmats.Bx822.data[0][0])*bmats.Bx822.shape[0]*bmats.Bx822.shape[1]);
    matlincomb_double_contiguous(bmats.Bx822, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}