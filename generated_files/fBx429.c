#include "stdafx.h"
#include "fBx429.h"

inline int fBx429(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_18_30, bmats.B_30_31, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx429.data[0][0], 0, sizeof(bmats.Bx429.data[0][0])*bmats.Bx429.shape[0]*bmats.Bx429.shape[1]);
    matlincomb_double_contiguous(bmats.Bx429, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}