#include "stdafx.h"
#include "fBx2606.h"

inline int fBx2606(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_31_7, bmats.B_7_29, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx2606.data[0][0], 0, sizeof(bmats.Bx2606.data[0][0])*bmats.Bx2606.shape[0]*bmats.Bx2606.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2606, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
