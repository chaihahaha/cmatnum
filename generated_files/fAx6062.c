#include "fAx6062.h"

inline int fAx6062(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 9;
    double_cmat A_mats[9] = {bmats.A_21_23, bmats.A_21_24, bmats.A_21_25, bmats.A_21_26, bmats.A_21_27, bmats.A_21_29, bmats.A_21_30, bmats.A_21_31, bmats.A_21_32, };
    double A_coeffs[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax6062, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
