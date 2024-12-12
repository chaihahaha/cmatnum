#include "stdafx.h"
#include "fBx12697.h"

inline int fBx12697(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_1_18, bmats.B_2_18, bmats.Bx12672, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx12697.data[0][0], 0, sizeof(bmats.Bx12697.data[0][0])*bmats.Bx12697.shape[0]*bmats.Bx12697.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12697, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
