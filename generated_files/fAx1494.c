#include "fAx1494.h"

inline int fAx1494(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_30_17, bmats.A_30_18, bmats.A_30_19, bmats.A_30_20, bmats.A_30_21, bmats.A_30_22, bmats.A_30_23, bmats.A_30_24, bmats.A_30_27, bmats.A_30_28, bmats.A_30_29, bmats.A_30_30, bmats.A_30_31, bmats.A_30_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax1494, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
