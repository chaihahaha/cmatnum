#include "stdafx.h"
#include "fBx9453.h"

inline int fBx9453(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_20_8, bmats.B_32_8, bmats.Bx9247, bmats.Bx9451, bmats.Bx9452, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx9453.data[0][0], 0, sizeof(bmats.Bx9453.data[0][0])*bmats.Bx9453.shape[0]*bmats.Bx9453.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9453, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
