#include "stdafx.h"
#include "fBx11028.h"

inline int fBx11028(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_11_4, bmats.B_14_6, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11028.data[0][0], 0, sizeof(bmats.Bx11028.data[0][0])*bmats.Bx11028.shape[0]*bmats.Bx11028.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11028, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
