#include "stdafx.h"
#include "fBx12549.h"

inline int fBx12549(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_6_15, bmats.B_6_2, bmats.Bx6798, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx12549.data[0][0], 0, sizeof(bmats.Bx12549.data[0][0])*bmats.Bx12549.shape[0]*bmats.Bx12549.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12549, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
