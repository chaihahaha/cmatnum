#include "fAx3020.h"

inline int fAx3020(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_26_1, bmats.A_26_10, bmats.A_26_11, bmats.A_26_12, bmats.A_26_13, bmats.A_26_14, bmats.A_26_15, bmats.A_26_16, bmats.A_26_2, bmats.A_26_3, bmats.A_26_5, bmats.A_26_6, bmats.A_26_7, bmats.A_26_8, bmats.Ax2874, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(bmats.Ax3020, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
