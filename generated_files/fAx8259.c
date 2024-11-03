#include "fAx8259.h"
#include "stdafx.h"

inline int fAx8259(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_15_1, bmats.A_15_10, bmats.A_15_13, bmats.A_15_14, bmats.A_15_15, bmats.A_15_16, bmats.A_15_2, bmats.A_15_3, bmats.A_15_4, bmats.A_15_5, bmats.A_15_6, bmats.A_15_7, bmats.A_15_8, bmats.A_15_9, };
    double A_coeffs[14] = {2, 2, 2, 2, -15, 2, 2, 2, 2, 2, 2, 2, 2, 2, };
    matlincomb_double_contiguous(bmats.Ax8259, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
