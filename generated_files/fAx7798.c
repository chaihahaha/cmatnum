#include "fAx7798.h"

inline int fAx7798(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 48;
    double_cmat A_mats[48] = {bmats.A_10_31, bmats.A_10_32, bmats.A_11_31, bmats.A_11_32, bmats.A_12_31, bmats.A_12_32, bmats.A_13_31, bmats.A_13_32, bmats.A_14_31, bmats.A_14_32, bmats.A_15_31, bmats.A_15_32, bmats.A_16_31, bmats.A_16_32, bmats.A_1_31, bmats.A_1_32, bmats.A_2_31, bmats.A_2_32, bmats.A_3_31, bmats.A_3_32, bmats.A_4_31, bmats.A_4_32, bmats.A_5_31, bmats.A_5_32, bmats.A_6_31, bmats.A_6_32, bmats.A_7_31, bmats.A_7_32, bmats.A_8_31, bmats.A_8_32, bmats.A_9_31, bmats.A_9_32, bmats.Ax645, bmats.Ax745, bmats.Ax748, bmats.Ax751, bmats.Ax754, bmats.Ax757, bmats.Ax760, bmats.Ax763, bmats.Ax766, bmats.Ax769, bmats.Ax772, bmats.Ax775, bmats.Ax778, bmats.Ax781, bmats.Ax784, bmats.Ax789, };
    double A_coeffs[48] = {1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax7798, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
