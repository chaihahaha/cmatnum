#include "fAx6064.h"

inline int fAx6064(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 8;
    double_cmat A_mats[8] = {bmats.A_21_23, bmats.A_21_24, bmats.A_21_25, bmats.A_21_26, bmats.A_21_27, bmats.A_21_28, bmats.A_21_31, bmats.A_21_32, };
    double A_coeffs[8] = {-1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax6064, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
