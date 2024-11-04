#include "stdafx.h"
#include "fAx4417.h"

int fAx4417(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_4_17, bmats.A_4_18, bmats.A_4_19, bmats.A_4_20, bmats.A_4_21, bmats.A_4_23, bmats.A_4_24, bmats.A_4_25, bmats.A_4_26, bmats.A_4_28, bmats.A_4_29, bmats.A_4_30, bmats.A_4_31, bmats.A_4_32, bmats.Ax4311, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(bmats.Ax4417, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
