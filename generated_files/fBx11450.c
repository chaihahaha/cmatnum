#include "stdafx.h"
#include "fBx11450.h"

inline int fBx11450(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 7;
    double_cmat B_mats[7] = {bmats.B_22_5, bmats.B_23_5, bmats.B_24_5, bmats.B_25_5, bmats.B_26_5, bmats.B_27_5, bmats.B_29_5, };
    double B_coeffs[7] = {1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx11450.data[0][0], 0, sizeof(bmats.Bx11450.data[0][0])*bmats.Bx11450.shape[0]*bmats.Bx11450.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11450, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
