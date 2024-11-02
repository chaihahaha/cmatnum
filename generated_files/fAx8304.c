#include "fAx8304.h"

inline int fAx8304(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_11_1, bmats.A_11_10, bmats.A_11_11, bmats.A_11_12, bmats.A_11_13, bmats.A_11_14, bmats.A_11_15, bmats.A_11_16, bmats.A_11_2, bmats.A_11_5, bmats.A_11_6, bmats.A_11_7, bmats.A_11_8, bmats.A_11_9, };
    double A_coeffs[14] = {2, 2, -15, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, };
    matlincomb_double_contiguous(bmats.Ax8304, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
