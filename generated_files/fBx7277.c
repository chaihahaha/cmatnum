#include "stdafx.h"
#include "fBx7277.h"

inline int fBx7277(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_15_22, bmats.B_6_10, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7277.data[0][0], 0, sizeof(bmats.Bx7277.data[0][0])*bmats.Bx7277.shape[0]*bmats.Bx7277.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7277, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}