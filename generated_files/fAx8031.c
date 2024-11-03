#include "fAx8031.h"
#include "stdafx.h"

inline int fAx8031(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 7;
    double_cmat A_mats[7] = {bmats.A_30_17, bmats.A_30_19, bmats.A_30_20, bmats.A_30_21, bmats.A_30_22, bmats.A_30_25, bmats.A_30_26, };
    double A_coeffs[7] = {-1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax8031, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
