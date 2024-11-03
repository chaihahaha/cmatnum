#include "fAx6372.h"
#include "stdafx.h"

inline int fAx6372(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 10;
    double_cmat A_mats[10] = {bmats.A_18_20, bmats.A_18_21, bmats.A_18_22, bmats.A_18_23, bmats.A_18_27, bmats.A_18_28, bmats.A_18_29, bmats.A_18_30, bmats.A_18_31, bmats.A_18_32, };
    double A_coeffs[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax6372, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
