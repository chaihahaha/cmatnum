#include "fAx2141.h"
#include "stdafx.h"

inline int fAx2141(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 40;
    double_cmat A_mats[40] = {bmats.A_17_29, bmats.A_17_30, bmats.A_18_29, bmats.A_18_30, bmats.A_21_29, bmats.A_21_30, bmats.A_22_29, bmats.A_22_30, bmats.A_23_29, bmats.A_23_30, bmats.A_24_29, bmats.A_24_30, bmats.A_25_29, bmats.A_25_30, bmats.A_26_29, bmats.A_26_30, bmats.A_27_29, bmats.A_27_30, bmats.A_28_29, bmats.A_28_30, bmats.A_29_29, bmats.A_30_29, bmats.A_30_30, bmats.A_31_29, bmats.A_31_30, bmats.A_32_29, bmats.A_32_30, bmats.Ax1076, bmats.Ax1079, bmats.Ax1082, bmats.Ax1085, bmats.Ax1088, bmats.Ax1094, bmats.Ax1097, bmats.Ax1100, bmats.Ax1103, bmats.Ax1106, bmats.Ax1115, bmats.Ax1118, bmats.Ax1130, };
    double A_coeffs[40] = {-16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -17, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax2141, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
