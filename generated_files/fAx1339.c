#include "stdafx.h"
#include "fAx1339.h"

int fAx1339(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 40;
    double_cmat A_mats[40] = {bmats.A_10_13, bmats.A_10_14, bmats.A_11_13, bmats.A_11_14, bmats.A_12_13, bmats.A_12_14, bmats.A_14_14, bmats.A_15_13, bmats.A_15_14, bmats.A_16_13, bmats.A_16_14, bmats.A_1_13, bmats.A_1_14, bmats.A_2_13, bmats.A_2_14, bmats.A_3_13, bmats.A_3_14, bmats.A_4_13, bmats.A_4_14, bmats.A_5_13, bmats.A_5_14, bmats.A_6_13, bmats.A_6_14, bmats.A_7_13, bmats.A_7_14, bmats.A_9_13, bmats.A_9_14, bmats.Ax1012, bmats.Ax1015, bmats.Ax1018, bmats.Ax1021, bmats.Ax1024, bmats.Ax1030, bmats.Ax1036, bmats.Ax1039, bmats.Ax1042, bmats.Ax1045, bmats.Ax1048, bmats.Ax1051, bmats.Ax1054, };
    double A_coeffs[40] = {1, -16, 1, -16, 1, -16, -17, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax1339, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
