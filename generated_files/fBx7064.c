#include "stdafx.h"
#include "fBx7064.h"

inline int fBx7064(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_16_11, bmats.B_2_32, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7064.data[0][0], 0, sizeof(bmats.Bx7064.data[0][0])*bmats.Bx7064.shape[0]*bmats.Bx7064.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7064, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
