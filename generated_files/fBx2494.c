#include "stdafx.h"
#include "fBx2494.h"

inline int fBx2494(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_27_29, bmats.B_28_29, bmats.B_31_29, bmats.Bx2493, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx2494.data[0][0], 0, sizeof(bmats.Bx2494.data[0][0])*bmats.Bx2494.shape[0]*bmats.Bx2494.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2494, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
