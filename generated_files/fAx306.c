#include "fAx306.h"

inline int fAx306(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_25_17, bmats.A_25_18, bmats.A_25_21, bmats.A_25_22, bmats.A_25_23, bmats.A_25_24, bmats.A_25_25, bmats.A_25_26, bmats.A_25_27, bmats.A_25_28, bmats.A_25_29, bmats.A_25_30, bmats.A_25_31, bmats.A_25_32, };
    double A_coeffs[14] = {2, 2, 2, 2, 2, 2, -15, 2, 2, 2, 2, 2, 2, 2, };
    matlincomb_double_contiguous(bmats.Ax306, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
