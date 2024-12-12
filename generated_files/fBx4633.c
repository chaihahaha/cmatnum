#include "stdafx.h"
#include "fBx4633.h"

inline int fBx4633(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 8;
    double_cmat B_mats[8] = {bmats.B_19_12, bmats.B_21_12, bmats.B_22_12, bmats.B_26_12, bmats.Bx4198, bmats.Bx4630, bmats.Bx4631, bmats.Bx4632, };
    double B_coeffs[8] = {1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx4633.data[0][0], 0, sizeof(bmats.Bx4633.data[0][0])*bmats.Bx4633.shape[0]*bmats.Bx4633.shape[1]);
    matlincomb_double_contiguous(bmats.Bx4633, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
