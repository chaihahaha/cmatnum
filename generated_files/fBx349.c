#include "stdafx.h"
#include "fBx349.h"

inline int fBx349(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_16, bmats.B_32_31, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx349.data[0][0], 0, sizeof(bmats.Bx349.data[0][0])*bmats.Bx349.shape[0]*bmats.Bx349.shape[1]);
    matlincomb_double_contiguous(bmats.Bx349, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
