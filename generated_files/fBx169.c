#include "stdafx.h"
#include "fBx169.h"

inline int fBx169(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_18_25, bmats.B_23_18, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx169.data[0][0], 0, sizeof(bmats.Bx169.data[0][0])*bmats.Bx169.shape[0]*bmats.Bx169.shape[1]);
    matlincomb_double_contiguous(bmats.Bx169, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
