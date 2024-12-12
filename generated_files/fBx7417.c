#include "stdafx.h"
#include "fBx7417.h"

inline int fBx7417(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_27_19, bmats.B_27_20, bmats.B_27_21, bmats.B_27_22, bmats.Bx7416, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx7417.data[0][0], 0, sizeof(bmats.Bx7417.data[0][0])*bmats.Bx7417.shape[0]*bmats.Bx7417.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7417, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
