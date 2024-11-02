#include "fAx2656.h"

inline int fAx2656(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 40;
    double_cmat A_mats[40] = {bmats.A_17_27, bmats.A_17_28, bmats.A_18_27, bmats.A_18_28, bmats.A_19_27, bmats.A_19_28, bmats.A_20_27, bmats.A_20_28, bmats.A_21_27, bmats.A_21_28, bmats.A_22_27, bmats.A_22_28, bmats.A_23_27, bmats.A_23_28, bmats.A_24_27, bmats.A_24_28, bmats.A_25_27, bmats.A_25_28, bmats.A_26_27, bmats.A_26_28, bmats.A_27_27, bmats.A_28_27, bmats.A_28_28, bmats.A_29_27, bmats.A_29_28, bmats.A_32_27, bmats.A_32_28, bmats.Ax1, bmats.Ax10, bmats.Ax15, bmats.Ax152, bmats.Ax1966, bmats.Ax2225, bmats.Ax23, bmats.Ax28, bmats.Ax34, bmats.Ax39, bmats.Ax45, bmats.Ax55, bmats.Ax61, };
    double A_coeffs[40] = {-16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -17, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax2656, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
