#include "fAx8025.h"
#include "stdafx.h"

inline int fAx8025(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 8;
    double_cmat A_mats[8] = {bmats.A_30_17, bmats.A_30_19, bmats.A_30_21, bmats.A_30_22, bmats.A_30_23, bmats.A_30_24, bmats.A_30_25, bmats.A_30_26, };
    double A_coeffs[8] = {-1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax8025, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
