#include "stdafx.h"
#include "fBx13262.h"

inline int fBx13262(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx10553, bmats.Bx11138, bmats.Bx11438, bmats.Bx11671, bmats.Bx12248, bmats.Bx12546, bmats.Bx12792, bmats.Bx12987, bmats.Bx13260, bmats.Bx13261, bmats.Bx1877, bmats.Bx3483, bmats.Bx5537, bmats.Bx6723, bmats.Bx7785, bmats.Bx8689, bmats.Bx9925, };
    double B_coeffs[17] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx13262.data[0][0], 0, sizeof(bmats.Bx13262.data[0][0])*bmats.Bx13262.shape[0]*bmats.Bx13262.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13262, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
