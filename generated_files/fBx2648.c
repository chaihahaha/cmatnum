#include "stdafx.h"
#include "fBx2648.h"

inline int fBx2648(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_28_29, bmats.B_32_28, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx2648.data[0][0], 0, sizeof(bmats.Bx2648.data[0][0])*bmats.Bx2648.shape[0]*bmats.Bx2648.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2648, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
