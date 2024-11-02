#include "fAx4311.h"

inline int fAx4311(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 48;
    double_cmat A_mats[48] = {bmats.A_17_3, bmats.A_17_4, bmats.A_18_3, bmats.A_18_4, bmats.A_19_3, bmats.A_19_4, bmats.A_20_3, bmats.A_20_4, bmats.A_21_3, bmats.A_21_4, bmats.A_22_3, bmats.A_22_4, bmats.A_23_3, bmats.A_23_4, bmats.A_24_3, bmats.A_24_4, bmats.A_25_3, bmats.A_25_4, bmats.A_26_3, bmats.A_26_4, bmats.A_27_3, bmats.A_27_4, bmats.A_28_3, bmats.A_28_4, bmats.A_29_3, bmats.A_29_4, bmats.A_30_3, bmats.A_30_4, bmats.A_31_3, bmats.A_31_4, bmats.A_32_3, bmats.A_32_4, bmats.Ax1781, bmats.Ax2143, bmats.Ax2483, bmats.Ax2765, bmats.Ax3122, bmats.Ax3351, bmats.Ax3595, bmats.Ax3807, bmats.Ax4096, bmats.Ax4236, bmats.Ax4297, bmats.Ax4300, bmats.Ax4303, bmats.Ax4306, bmats.Ax4309, bmats.Ax913, };
    double A_coeffs[48] = {1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax4311, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
