#include "fBx13262.h"

inline int fBx13262(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 23;
    double_cmat B_mats[23] = {bmats.B_12_5, bmats.B_14_5, bmats.B_15_5, bmats.B_17_5, bmats.B_18_5, bmats.B_19_5, bmats.B_20_5, bmats.B_21_5, bmats.B_22_5, bmats.B_23_5, bmats.B_24_5, bmats.B_25_5, bmats.B_26_5, bmats.B_27_5, bmats.B_28_5, bmats.B_29_5, bmats.B_30_5, bmats.B_31_5, bmats.B_32_5, bmats.B_4_5, bmats.B_7_5, bmats.B_9_5, bmats.Bx11433, };
    double B_coeffs[23] = {1, 1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx13262, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
