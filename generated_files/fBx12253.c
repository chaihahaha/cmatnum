#include "stdafx.h"
#include "fBx12253.h"

inline int fBx12253(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_21_15, bmats.B_21_16, bmats.B_21_5, bmats.Bx12250, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx12253.data[0][0], 0, sizeof(bmats.Bx12253.data[0][0])*bmats.Bx12253.shape[0]*bmats.Bx12253.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12253, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
