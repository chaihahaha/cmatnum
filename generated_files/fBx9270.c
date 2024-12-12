#include "stdafx.h"
#include "fBx9270.h"

inline int fBx9270(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_24_24, bmats.B_26_24, bmats.B_27_24, bmats.B_30_24, bmats.B_31_24, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx9270.data[0][0], 0, sizeof(bmats.Bx9270.data[0][0])*bmats.Bx9270.shape[0]*bmats.Bx9270.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9270, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
