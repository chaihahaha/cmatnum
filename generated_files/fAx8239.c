#include "stdafx.h"
#include "fAx8239.h"

int fAx8239(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_19_19, bmats.A_19_20, bmats.A_19_21, bmats.A_19_22, bmats.A_19_23, bmats.A_19_24, bmats.A_19_25, bmats.A_19_26, bmats.A_19_27, bmats.A_19_28, bmats.A_19_29, bmats.A_19_30, bmats.A_19_31, bmats.A_19_32, };
    double A_coeffs[14] = {-15, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, };
    matlincomb_double_contiguous(bmats.Ax8239, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
