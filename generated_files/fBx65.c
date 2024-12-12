#include "stdafx.h"
#include "fBx65.h"

inline int fBx65(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_18_27, bmats.B_27_18, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx65.data[0][0], 0, sizeof(bmats.Bx65.data[0][0])*bmats.Bx65.shape[0]*bmats.Bx65.shape[1]);
    matlincomb_double_contiguous(bmats.Bx65, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
