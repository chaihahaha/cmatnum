#include "stdafx.h"
#include "fBx11648.h"

inline int fBx11648(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 1;
    double_cmat B_mats[1] = {bmats.B_21_25, };
    double B_coeffs[1] = {-1, };
memset(&bmats.Bx11648.data[0][0], 0, sizeof(bmats.Bx11648.data[0][0])*bmats.Bx11648.shape[0]*bmats.Bx11648.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11648, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
