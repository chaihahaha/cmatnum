#include "stdafx.h"
#include "fBx9084.h"

inline int fBx9084(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_1_9, bmats.B_4_1, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx9084.data[0][0], 0, sizeof(bmats.Bx9084.data[0][0])*bmats.Bx9084.shape[0]*bmats.Bx9084.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9084, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}