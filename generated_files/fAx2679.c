#include "stdafx.h"
#include "fAx2679.h"

int fAx2679(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_27_1, bmats.A_27_12, bmats.A_27_13, bmats.A_27_14, bmats.A_27_15, bmats.A_27_16, bmats.A_27_2, bmats.A_27_3, bmats.A_27_4, bmats.A_27_5, bmats.A_27_6, bmats.A_27_7, bmats.A_27_8, bmats.A_27_9, bmats.Ax2627, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(bmats.Ax2679, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
