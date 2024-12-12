#include "stdafx.h"
#include "fBx11336.h"

inline int fBx11336(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_19_31, bmats.B_31_22, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11336.data[0][0], 0, sizeof(bmats.Bx11336.data[0][0])*bmats.Bx11336.shape[0]*bmats.Bx11336.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11336, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
