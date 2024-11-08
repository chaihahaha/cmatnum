#include "stdafx.h"
#include "fAx8027.h"

int fAx8027(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 7;
    double_cmat A_mats[7] = {bmats.A_30_17, bmats.A_30_19, bmats.A_30_20, bmats.A_30_23, bmats.A_30_24, bmats.A_30_25, bmats.A_30_26, };
    double A_coeffs[7] = {-1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax8027, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
