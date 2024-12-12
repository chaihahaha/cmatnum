#include "stdafx.h"
#include "fBx882.h"

inline int fBx882(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_31_1, bmats.B_31_14, bmats.B_31_2, bmats.B_31_3, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx882.data[0][0], 0, sizeof(bmats.Bx882.data[0][0])*bmats.Bx882.shape[0]*bmats.Bx882.shape[1]);
    matlincomb_double_contiguous(bmats.Bx882, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
