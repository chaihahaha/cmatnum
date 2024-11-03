#include "fAx4550.h"
#include "stdafx.h"

inline int fAx4550(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_19_1, bmats.A_19_10, bmats.A_19_11, bmats.A_19_12, bmats.A_19_15, bmats.A_19_16, bmats.A_19_2, bmats.A_19_3, bmats.A_19_4, bmats.A_19_5, bmats.A_19_6, bmats.A_19_7, bmats.A_19_8, bmats.A_19_9, bmats.Ax4519, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(bmats.Ax4550, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
