#include "fAx591.h"

inline int fAx591(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_5_1, bmats.A_5_10, bmats.A_5_11, bmats.A_5_12, bmats.A_5_13, bmats.A_5_14, bmats.A_5_2, bmats.A_5_3, bmats.A_5_4, bmats.A_5_5, bmats.A_5_6, bmats.A_5_7, bmats.A_5_8, bmats.A_5_9, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax591, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
