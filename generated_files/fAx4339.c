#include "fAx4339.h"

inline int fAx4339(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_3_1, bmats.A_3_10, bmats.A_3_11, bmats.A_3_12, bmats.A_3_13, bmats.A_3_14, bmats.A_3_15, bmats.A_3_16, bmats.A_3_2, bmats.A_3_5, bmats.A_3_6, bmats.A_3_7, bmats.A_3_8, bmats.A_3_9, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax4339, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
