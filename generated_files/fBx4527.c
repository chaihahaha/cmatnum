#include "stdafx.h"
#include "fBx4527.h"

inline int fBx4527(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_24_28, bmats.B_28_19, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx4527.data[0][0], 0, sizeof(bmats.Bx4527.data[0][0])*bmats.Bx4527.shape[0]*bmats.Bx4527.shape[1]);
    matlincomb_double_contiguous(bmats.Bx4527, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
