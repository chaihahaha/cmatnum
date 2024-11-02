#include "fAx4522.h"

inline int fAx4522(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 40;
    double_cmat A_mats[40] = {bmats.A_10_3, bmats.A_10_4, bmats.A_11_3, bmats.A_11_4, bmats.A_12_3, bmats.A_12_4, bmats.A_13_3, bmats.A_13_4, bmats.A_14_3, bmats.A_14_4, bmats.A_15_3, bmats.A_15_4, bmats.A_16_3, bmats.A_16_4, bmats.A_3_3, bmats.A_3_4, bmats.A_4_4, bmats.A_5_3, bmats.A_5_4, bmats.A_6_3, bmats.A_6_4, bmats.A_7_3, bmats.A_7_4, bmats.A_8_3, bmats.A_8_4, bmats.A_9_3, bmats.A_9_4, bmats.Ax1590, bmats.Ax2152, bmats.Ax2489, bmats.Ax2771, bmats.Ax3057, bmats.Ax3357, bmats.Ax3601, bmats.Ax3813, bmats.Ax4102, bmats.Ax4242, bmats.Ax4339, bmats.Ax4366, bmats.Ax944, };
    double A_coeffs[40] = {1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, -17, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax4522, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
