#include "stdafx.h"
#include "fBx420.h"

inline int fBx420(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_2_6, bmats.B_6_15, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx420.data[0][0], 0, sizeof(bmats.Bx420.data[0][0])*bmats.Bx420.shape[0]*bmats.Bx420.shape[1]);
    matlincomb_double_contiguous(bmats.Bx420, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}