#include "fAx4420.h"

inline int fAx4420(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 40;
    double_cmat A_mats[40] = {bmats.A_17_19, bmats.A_17_20, bmats.A_18_19, bmats.A_18_20, bmats.A_19_19, bmats.A_19_20, bmats.A_20_20, bmats.A_21_19, bmats.A_21_20, bmats.A_22_19, bmats.A_22_20, bmats.A_24_19, bmats.A_24_20, bmats.A_25_19, bmats.A_25_20, bmats.A_26_19, bmats.A_26_20, bmats.A_27_19, bmats.A_27_20, bmats.A_29_19, bmats.A_29_20, bmats.A_30_19, bmats.A_30_20, bmats.A_31_19, bmats.A_31_20, bmats.A_32_19, bmats.A_32_20, bmats.Ax105, bmats.Ax123, bmats.Ax1569, bmats.Ax187, bmats.Ax199, bmats.Ax2149, bmats.Ax31, bmats.Ax4351, bmats.Ax4354, bmats.Ax4357, bmats.Ax4376, bmats.Ax69, bmats.Ax923, };
    double A_coeffs[40] = {1, -16, 1, -16, 1, -16, -17, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax4420, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
