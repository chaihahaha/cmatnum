#include "stdafx.h"
#include "fBx11496.h"

inline int fBx11496(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_1_21, bmats.Bx11442, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11496.data[0][0], 0, sizeof(bmats.Bx11496.data[0][0])*bmats.Bx11496.shape[0]*bmats.Bx11496.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11496, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
