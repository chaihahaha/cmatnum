#include "fAx2392.h"

inline int fAx2392(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_12_17, bmats.A_12_18, bmats.A_12_19, bmats.A_12_20, bmats.A_12_21, bmats.A_12_22, bmats.A_12_23, bmats.A_12_24, bmats.A_12_27, bmats.A_12_28, bmats.A_12_29, bmats.A_12_30, bmats.A_12_31, bmats.A_12_32, bmats.Ax2277, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(bmats.Ax2392, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
