#include "stdafx.h"
#include "fAx8035.h"

int fAx8035(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 7;
    double_cmat A_mats[7] = {bmats.A_30_17, bmats.A_30_19, bmats.A_30_20, bmats.A_30_21, bmats.A_30_22, bmats.A_30_23, bmats.A_30_24, };
    double A_coeffs[7] = {-1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax8035, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
