#include "stdafx.h"
#include "fBx7163.h"

inline int fBx7163(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_1_11, bmats.B_3_17, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7163.data[0][0], 0, sizeof(bmats.Bx7163.data[0][0])*bmats.Bx7163.shape[0]*bmats.Bx7163.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7163, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
