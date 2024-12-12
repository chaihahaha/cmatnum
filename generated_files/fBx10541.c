#include "stdafx.h"
#include "fBx10541.h"

inline int fBx10541(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_21_19, bmats.B_21_20, bmats.Bx9934, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx10541.data[0][0], 0, sizeof(bmats.Bx10541.data[0][0])*bmats.Bx10541.shape[0]*bmats.Bx10541.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10541, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
