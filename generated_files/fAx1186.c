#include "fAx1186.h"

inline int fAx1186(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_16_17, bmats.A_16_18, bmats.A_16_19, bmats.A_16_20, bmats.A_16_21, bmats.A_16_22, bmats.A_16_23, bmats.A_16_24, bmats.A_16_25, bmats.A_16_26, bmats.A_16_27, bmats.A_16_28, bmats.A_16_29, bmats.A_16_30, bmats.A_16_32, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax1186, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
