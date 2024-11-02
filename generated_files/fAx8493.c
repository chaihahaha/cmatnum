#include "fAx8493.h"

inline int fAx8493(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 40;
    double_cmat A_mats[40] = {bmats.A_17_31, bmats.A_17_32, bmats.A_18_31, bmats.A_18_32, bmats.A_19_31, bmats.A_19_32, bmats.A_20_31, bmats.A_20_32, bmats.A_21_31, bmats.A_21_32, bmats.A_22_31, bmats.A_22_32, bmats.A_23_31, bmats.A_23_32, bmats.A_24_31, bmats.A_24_32, bmats.A_25_31, bmats.A_25_32, bmats.A_26_31, bmats.A_26_32, bmats.A_27_31, bmats.A_27_32, bmats.A_28_31, bmats.A_28_32, bmats.A_31_31, bmats.A_32_31, bmats.A_32_32, bmats.Ax533, bmats.Ax600, bmats.Ax609, bmats.Ax612, bmats.Ax618, bmats.Ax621, bmats.Ax624, bmats.Ax627, bmats.Ax630, bmats.Ax633, bmats.Ax636, bmats.Ax639, bmats.Ax667, };
    double A_coeffs[40] = {-16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -17, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax8493, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
