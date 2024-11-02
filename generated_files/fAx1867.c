#include "fAx1867.h"

inline int fAx1867(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 48;
    double_cmat A_mats[48] = {bmats.A_17_13, bmats.A_17_14, bmats.A_18_13, bmats.A_18_14, bmats.A_19_13, bmats.A_19_14, bmats.A_20_13, bmats.A_20_14, bmats.A_21_13, bmats.A_21_14, bmats.A_22_13, bmats.A_22_14, bmats.A_23_13, bmats.A_23_14, bmats.A_24_13, bmats.A_24_14, bmats.A_25_13, bmats.A_25_14, bmats.A_26_13, bmats.A_26_14, bmats.A_27_13, bmats.A_27_14, bmats.A_28_13, bmats.A_28_14, bmats.A_29_13, bmats.A_29_14, bmats.A_30_13, bmats.A_30_14, bmats.A_31_13, bmats.A_31_14, bmats.A_32_13, bmats.A_32_14, bmats.Ax482, bmats.Ax485, bmats.Ax488, bmats.Ax491, bmats.Ax494, bmats.Ax497, bmats.Ax500, bmats.Ax503, bmats.Ax506, bmats.Ax509, bmats.Ax512, bmats.Ax515, bmats.Ax518, bmats.Ax521, bmats.Ax524, bmats.Ax527, };
    double A_coeffs[48] = {-16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax1867, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
