#include "stdafx.h"
#include "fBx2485.h"

inline int fBx2485(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_15_29, bmats.B_1_29, bmats.B_2_29, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx2485.data[0][0], 0, sizeof(bmats.Bx2485.data[0][0])*bmats.Bx2485.shape[0]*bmats.Bx2485.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2485, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
