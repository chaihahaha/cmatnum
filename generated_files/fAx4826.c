#include "stdafx.h"
#include "fAx4826.h"

int fAx4826(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_1_17, bmats.A_1_18, bmats.A_1_19, bmats.A_1_20, bmats.A_1_23, bmats.A_1_24, bmats.A_1_25, bmats.A_1_26, bmats.A_1_27, bmats.A_1_28, bmats.A_1_29, bmats.A_1_30, bmats.A_1_31, bmats.A_1_32, bmats.Ax4768, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(bmats.Ax4826, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
