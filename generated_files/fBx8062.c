#include "stdafx.h"
#include "fBx8062.h"

inline int fBx8062(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_18_16, bmats.B_32_26, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx8062.data[0][0], 0, sizeof(bmats.Bx8062.data[0][0])*bmats.Bx8062.shape[0]*bmats.Bx8062.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8062, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
