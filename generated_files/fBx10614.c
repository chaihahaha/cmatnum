#include "stdafx.h"
#include "fBx10614.h"

inline int fBx10614(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_21_7, bmats.B_6_5, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx10614.data[0][0], 0, sizeof(bmats.Bx10614.data[0][0])*bmats.Bx10614.shape[0]*bmats.Bx10614.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10614, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
