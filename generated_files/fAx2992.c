#include "fAx2992.h"
#include "stdafx.h"

inline int fAx2992(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_10_17, bmats.A_10_18, bmats.A_10_19, bmats.A_10_20, bmats.A_10_21, bmats.A_10_22, bmats.A_10_25, bmats.A_10_26, bmats.A_10_27, bmats.A_10_28, bmats.A_10_29, bmats.A_10_30, bmats.A_10_31, bmats.A_10_32, bmats.Ax2836, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(bmats.Ax2992, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
