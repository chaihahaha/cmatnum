#include "fAx4206.h"

inline int fAx4206(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_5_17, bmats.A_5_18, bmats.A_5_19, bmats.A_5_20, bmats.A_5_21, bmats.A_5_22, bmats.A_5_23, bmats.A_5_24, bmats.A_5_25, bmats.A_5_26, bmats.A_5_29, bmats.A_5_30, bmats.A_5_31, bmats.A_5_32, bmats.Ax4141, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(bmats.Ax4206, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
