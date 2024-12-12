#include "stdafx.h"
#include "fBx987.h"

inline int fBx987(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_27_30, bmats.B_32_11, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx987.data[0][0], 0, sizeof(bmats.Bx987.data[0][0])*bmats.Bx987.shape[0]*bmats.Bx987.shape[1]);
    matlincomb_double_contiguous(bmats.Bx987, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
