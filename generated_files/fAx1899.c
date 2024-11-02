#include "fAx1899.h"

inline int fAx1899(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 48;
    double_cmat A_mats[48] = {bmats.A_10_29, bmats.A_10_30, bmats.A_11_29, bmats.A_11_30, bmats.A_12_29, bmats.A_12_30, bmats.A_13_29, bmats.A_13_30, bmats.A_14_29, bmats.A_14_30, bmats.A_15_29, bmats.A_15_30, bmats.A_16_29, bmats.A_16_30, bmats.A_1_29, bmats.A_1_30, bmats.A_2_29, bmats.A_2_30, bmats.A_3_29, bmats.A_3_30, bmats.A_4_29, bmats.A_4_30, bmats.A_5_29, bmats.A_5_30, bmats.A_6_29, bmats.A_6_30, bmats.A_7_29, bmats.A_7_30, bmats.A_8_29, bmats.A_8_30, bmats.A_9_29, bmats.A_9_30, bmats.Ax396, bmats.Ax399, bmats.Ax402, bmats.Ax405, bmats.Ax408, bmats.Ax411, bmats.Ax414, bmats.Ax417, bmats.Ax420, bmats.Ax423, bmats.Ax426, bmats.Ax429, bmats.Ax432, bmats.Ax435, bmats.Ax438, bmats.Ax441, };
    double A_coeffs[48] = {-16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax1899, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
