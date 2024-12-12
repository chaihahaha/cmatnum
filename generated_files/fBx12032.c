#include "stdafx.h"
#include "fBx12032.h"

inline int fBx12032(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_16_5, bmats.B_2_16, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12032.data[0][0], 0, sizeof(bmats.Bx12032.data[0][0])*bmats.Bx12032.shape[0]*bmats.Bx12032.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12032, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
