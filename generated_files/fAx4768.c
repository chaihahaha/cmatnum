#include "fAx4768.h"

inline int fAx4768(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 48;
    double_cmat A_mats[48] = {bmats.A_17_1, bmats.A_17_2, bmats.A_18_1, bmats.A_18_2, bmats.A_19_1, bmats.A_19_2, bmats.A_20_1, bmats.A_20_2, bmats.A_21_1, bmats.A_21_2, bmats.A_22_1, bmats.A_22_2, bmats.A_23_1, bmats.A_23_2, bmats.A_24_1, bmats.A_24_2, bmats.A_25_1, bmats.A_25_2, bmats.A_26_1, bmats.A_26_2, bmats.A_27_1, bmats.A_27_2, bmats.A_28_1, bmats.A_28_2, bmats.A_29_1, bmats.A_29_2, bmats.A_30_1, bmats.A_30_2, bmats.A_31_1, bmats.A_31_2, bmats.A_32_1, bmats.A_32_2, bmats.Ax1763, bmats.Ax2125, bmats.Ax2633, bmats.Ax2882, bmats.Ax3108, bmats.Ax3507, bmats.Ax3720, bmats.Ax3875, bmats.Ax4081, bmats.Ax4392, bmats.Ax4527, bmats.Ax4586, bmats.Ax4670, bmats.Ax4673, bmats.Ax4676, bmats.Ax643, };
    double A_coeffs[48] = {-16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax4768, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
