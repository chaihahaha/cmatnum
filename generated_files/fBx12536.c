#include "stdafx.h"
#include "fBx12536.h"

inline int fBx12536(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_20_15, bmats.B_20_16, bmats.B_20_3, bmats.B_20_4, bmats.B_20_5, bmats.Bx12532, };
    double B_coeffs[6] = {1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx12536.data[0][0], 0, sizeof(bmats.Bx12536.data[0][0])*bmats.Bx12536.shape[0]*bmats.Bx12536.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12536, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
