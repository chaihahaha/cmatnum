#include "fAx5843.h"

inline int fAx5843(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_12_10, bmats.A_12_11, bmats.A_12_13, bmats.A_12_14, bmats.A_12_15, bmats.A_12_16, bmats.A_12_3, bmats.A_12_4, bmats.A_12_5, bmats.A_12_6, bmats.A_12_7, bmats.A_12_8, bmats.A_12_9, };
    double A_coeffs[13] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax5843, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
