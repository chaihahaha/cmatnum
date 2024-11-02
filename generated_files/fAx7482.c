#include "fAx7482.h"

inline int fAx7482(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_5_1, bmats.A_5_10, bmats.A_5_11, bmats.A_5_12, bmats.A_5_13, bmats.A_5_14, bmats.A_5_15, bmats.A_5_16, bmats.A_5_2, bmats.A_5_3, bmats.A_5_4, bmats.A_5_5, bmats.A_5_8, bmats.A_5_9, };
    double A_coeffs[14] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, -15, 2, 2, };
    matlincomb_double_contiguous(bmats.Ax7482, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
