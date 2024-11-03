#include "fAx6610.h"
#include "stdafx.h"

inline int fAx6610(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 9;
    double_cmat A_mats[9] = {bmats.A_17_18, bmats.A_17_21, bmats.A_17_22, bmats.A_17_23, bmats.A_17_24, bmats.A_17_25, bmats.A_17_26, bmats.A_17_27, bmats.A_17_28, };
    double A_coeffs[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax6610, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
