#include "stdafx.h"
#include "fBx12243.h"

inline int fBx12243(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_21_22, bmats.B_21_32, bmats.Bx1845, bmats.Bx5521, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx12243.data[0][0], 0, sizeof(bmats.Bx12243.data[0][0])*bmats.Bx12243.shape[0]*bmats.Bx12243.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12243, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}