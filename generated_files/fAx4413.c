#include "fAx4413.h"

inline int fAx4413(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_4_17, bmats.A_4_18, bmats.A_4_19, bmats.A_4_20, bmats.A_4_21, bmats.A_4_22, bmats.A_4_23, bmats.A_4_24, bmats.A_4_27, bmats.A_4_28, bmats.A_4_29, bmats.A_4_30, bmats.A_4_31, bmats.A_4_32, bmats.Ax4311, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(bmats.Ax4413, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
