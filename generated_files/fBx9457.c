#include "stdafx.h"
#include "fBx9457.h"

inline int fBx9457(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_5_24, bmats.Bx9232, bmats.Bx9455, bmats.Bx9456, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx9457.data[0][0], 0, sizeof(bmats.Bx9457.data[0][0])*bmats.Bx9457.shape[0]*bmats.Bx9457.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9457, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
