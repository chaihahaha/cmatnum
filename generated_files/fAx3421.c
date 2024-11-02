#include "fAx3421.h"

inline int fAx3421(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_15_17, bmats.A_15_18, bmats.A_15_19, bmats.A_15_20, bmats.A_15_21, bmats.A_15_22, bmats.A_15_25, bmats.A_15_26, bmats.A_15_27, bmats.A_15_28, bmats.A_15_29, bmats.A_15_30, bmats.A_15_31, bmats.A_15_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax3421, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
