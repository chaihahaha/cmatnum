#include "stdafx.h"
#include "fAx6880.h"

int fAx6880(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 10;
    double_cmat A_mats[10] = {bmats.A_25_17, bmats.A_25_19, bmats.A_25_20, bmats.A_25_21, bmats.A_25_22, bmats.A_25_23, bmats.A_25_24, bmats.A_25_26, bmats.A_25_27, bmats.A_25_28, };
    double A_coeffs[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax6880, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
