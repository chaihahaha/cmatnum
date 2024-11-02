#include "fAx654.h"

inline int fAx654(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 42;
    double_cmat A_mats[42] = {bmats.A_10_15, bmats.A_10_16, bmats.A_11_15, bmats.A_11_16, bmats.A_12_15, bmats.A_12_16, bmats.A_13_15, bmats.A_13_16, bmats.A_14_15, bmats.A_14_16, bmats.A_1_15, bmats.A_1_16, bmats.A_2_15, bmats.A_2_16, bmats.A_3_15, bmats.A_3_16, bmats.A_4_15, bmats.A_4_16, bmats.A_5_15, bmats.A_5_16, bmats.A_6_15, bmats.A_6_16, bmats.A_7_15, bmats.A_7_16, bmats.A_8_15, bmats.A_8_16, bmats.A_9_15, bmats.A_9_16, bmats.Ax392, bmats.Ax556, bmats.Ax562, bmats.Ax565, bmats.Ax568, bmats.Ax573, bmats.Ax576, bmats.Ax579, bmats.Ax582, bmats.Ax585, bmats.Ax588, bmats.Ax591, bmats.Ax594, bmats.Ax652, };
    double A_coeffs[42] = {-16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax654, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
