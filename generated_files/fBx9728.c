#include "stdafx.h"
#include "fBx9728.h"

inline int fBx9728(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_8_22, bmats.B_8_23, bmats.B_8_32, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx9728.data[0][0], 0, sizeof(bmats.Bx9728.data[0][0])*bmats.Bx9728.shape[0]*bmats.Bx9728.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9728, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
