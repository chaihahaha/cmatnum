#include "stdafx.h"
#include "fAx8004.h"

int fAx8004(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_30_17, bmats.A_30_18, bmats.A_30_19, bmats.A_30_20, bmats.A_30_21, bmats.A_30_22, bmats.A_30_23, bmats.A_30_24, bmats.A_30_25, bmats.A_30_26, bmats.A_30_27, bmats.A_30_28, bmats.A_30_31, };
    double A_coeffs[13] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax8004, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
