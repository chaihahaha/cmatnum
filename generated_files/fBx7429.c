#include "stdafx.h"
#include "fBx7429.h"

inline int fBx7429(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.B_11_17, bmats.B_11_18, bmats.B_11_19, bmats.B_11_20, bmats.B_11_21, bmats.B_11_22, bmats.B_11_23, bmats.B_11_24, bmats.B_11_25, bmats.Bx6247, };
    double B_coeffs[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx7429.data[0][0], 0, sizeof(bmats.Bx7429.data[0][0])*bmats.Bx7429.shape[0]*bmats.Bx7429.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7429, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
