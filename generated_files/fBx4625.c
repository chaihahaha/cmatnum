#include "stdafx.h"
#include "fBx4625.h"

inline int fBx4625(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 9;
    double_cmat B_mats[9] = {bmats.B_20_28, bmats.B_21_28, bmats.B_22_28, bmats.B_25_28, bmats.B_26_28, bmats.B_27_28, bmats.Bx4228, bmats.Bx4568, bmats.Bx4624, };
    double B_coeffs[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx4625.data[0][0], 0, sizeof(bmats.Bx4625.data[0][0])*bmats.Bx4625.shape[0]*bmats.Bx4625.shape[1]);
    matlincomb_double_contiguous(bmats.Bx4625, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
