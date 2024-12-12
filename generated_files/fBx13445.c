#include "stdafx.h"
#include "fBx13445.h"

inline int fBx13445(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_11_16, bmats.B_15_16, bmats.Bx13373, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx13445.data[0][0], 0, sizeof(bmats.Bx13445.data[0][0])*bmats.Bx13445.shape[0]*bmats.Bx13445.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13445, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
