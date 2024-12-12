#include "stdafx.h"
#include "fBx11819.h"

inline int fBx11819(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_4_1, bmats.Bx9087, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11819.data[0][0], 0, sizeof(bmats.Bx11819.data[0][0])*bmats.Bx11819.shape[0]*bmats.Bx11819.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11819, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
