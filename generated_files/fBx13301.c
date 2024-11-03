#include "fBx13301.h"
#include "stdafx.h"

inline int fBx13301(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_17_27, bmats.B_18_27, bmats.B_19_27, bmats.B_20_27, bmats.B_21_27, bmats.B_22_27, bmats.B_23_27, bmats.B_24_27, bmats.B_25_27, bmats.B_26_27, bmats.B_27_27, bmats.B_28_27, bmats.B_29_27, bmats.B_30_27, bmats.B_31_27, bmats.B_32_27, bmats.Bx5976, };
    double B_coeffs[17] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, };
    matlincomb_double_contiguous(bmats.Bx13301, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
