#include "fAx8379.h"

inline int fAx8379(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_9_1, bmats.A_9_10, bmats.A_9_11, bmats.A_9_12, bmats.A_9_13, bmats.A_9_14, bmats.A_9_15, bmats.A_9_16, bmats.A_9_4, bmats.A_9_5, bmats.A_9_6, bmats.A_9_7, bmats.A_9_8, bmats.A_9_9, };
    double A_coeffs[14] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, -15, };
    matlincomb_double_contiguous(bmats.Ax8379, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
