#include "fAx7799.h"
#include "stdafx.h"

inline int fAx7799(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 48;
    double_cmat A_mats[48] = {bmats.A_17_15, bmats.A_17_16, bmats.A_18_15, bmats.A_18_16, bmats.A_19_15, bmats.A_19_16, bmats.A_20_15, bmats.A_20_16, bmats.A_21_15, bmats.A_21_16, bmats.A_22_15, bmats.A_22_16, bmats.A_23_15, bmats.A_23_16, bmats.A_24_15, bmats.A_24_16, bmats.A_25_15, bmats.A_25_16, bmats.A_26_15, bmats.A_26_16, bmats.A_27_15, bmats.A_27_16, bmats.A_28_15, bmats.A_28_16, bmats.A_29_15, bmats.A_29_16, bmats.A_30_15, bmats.A_30_16, bmats.A_31_15, bmats.A_31_16, bmats.A_32_15, bmats.A_32_16, bmats.Ax660, bmats.Ax676, bmats.Ax679, bmats.Ax682, bmats.Ax685, bmats.Ax688, bmats.Ax691, bmats.Ax694, bmats.Ax697, bmats.Ax700, bmats.Ax703, bmats.Ax706, bmats.Ax709, bmats.Ax712, bmats.Ax715, bmats.Ax720, };
    double A_coeffs[48] = {1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax7799, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
