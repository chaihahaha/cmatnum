#include "stdafx.h"
#include "fBx2961.h"

inline int fBx2961(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_12_29, bmats.B_12_30, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx2961.data[0][0], 0, sizeof(bmats.Bx2961.data[0][0])*bmats.Bx2961.shape[0]*bmats.Bx2961.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2961, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
