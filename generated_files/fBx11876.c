#include "stdafx.h"
#include "fBx11876.h"

inline int fBx11876(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_5_3, bmats.B_7_5, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11876.data[0][0], 0, sizeof(bmats.Bx11876.data[0][0])*bmats.Bx11876.shape[0]*bmats.Bx11876.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11876, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
