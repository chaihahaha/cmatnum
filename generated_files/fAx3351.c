#include "fAx3351.h"

inline int fAx3351(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_25_1, bmats.A_25_10, bmats.A_25_11, bmats.A_25_12, bmats.A_25_13, bmats.A_25_14, bmats.A_25_15, bmats.A_25_16, bmats.A_25_2, bmats.A_25_5, bmats.A_25_6, bmats.A_25_7, bmats.A_25_8, bmats.A_25_9, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax3351, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
