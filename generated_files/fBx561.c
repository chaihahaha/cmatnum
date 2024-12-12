#include "stdafx.h"
#include "fBx561.h"

inline int fBx561(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_19_23, bmats.B_23_31, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx561.data[0][0], 0, sizeof(bmats.Bx561.data[0][0])*bmats.Bx561.shape[0]*bmats.Bx561.shape[1]);
    matlincomb_double_contiguous(bmats.Bx561, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
