#include "fAx3853.h"

inline int fAx3853(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_6_17, bmats.A_6_18, bmats.A_6_19, bmats.A_6_20, bmats.A_6_23, bmats.A_6_24, bmats.A_6_25, bmats.A_6_26, bmats.A_6_27, bmats.A_6_28, bmats.A_6_29, bmats.A_6_30, bmats.A_6_31, bmats.A_6_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax3853, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
