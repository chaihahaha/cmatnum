#include "fAx2545.h"

inline int fAx2545(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 40;
    double_cmat A_mats[40] = {bmats.A_10_11, bmats.A_10_12, bmats.A_11_11, bmats.A_12_11, bmats.A_12_12, bmats.A_14_11, bmats.A_14_12, bmats.A_15_11, bmats.A_15_12, bmats.A_1_11, bmats.A_1_12, bmats.A_2_11, bmats.A_2_12, bmats.A_3_11, bmats.A_3_12, bmats.A_4_11, bmats.A_4_12, bmats.A_5_11, bmats.A_5_12, bmats.A_6_11, bmats.A_6_12, bmats.A_7_11, bmats.A_7_12, bmats.A_8_11, bmats.A_8_12, bmats.A_9_11, bmats.A_9_12, bmats.Ax1255, bmats.Ax2175, bmats.Ax2178, bmats.Ax2181, bmats.Ax2187, bmats.Ax2193, bmats.Ax2196, bmats.Ax2199, bmats.Ax2202, bmats.Ax2205, bmats.Ax2208, bmats.Ax2211, bmats.Ax2214, };
    double A_coeffs[40] = {-16, 1, -17, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax2545, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
