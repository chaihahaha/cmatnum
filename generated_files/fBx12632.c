#include "stdafx.h"
#include "fBx12632.h"

inline int fBx12632(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_3_2, bmats.Bx11776, bmats.Bx12631, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx12632.data[0][0], 0, sizeof(bmats.Bx12632.data[0][0])*bmats.Bx12632.shape[0]*bmats.Bx12632.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12632, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
