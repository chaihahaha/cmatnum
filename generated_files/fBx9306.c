#include "stdafx.h"
#include "fBx9306.h"

inline int fBx9306(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx9206, bmats.Bx9210, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx9306.data[0][0], 0, sizeof(bmats.Bx9306.data[0][0])*bmats.Bx9306.shape[0]*bmats.Bx9306.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9306, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}