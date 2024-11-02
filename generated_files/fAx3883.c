#include "fAx3883.h"

inline int fAx3883(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_7_19, bmats.A_7_20, bmats.A_7_21, bmats.A_7_22, bmats.A_7_23, bmats.A_7_24, bmats.A_7_25, bmats.A_7_26, bmats.A_7_27, bmats.A_7_28, bmats.A_7_29, bmats.A_7_30, bmats.A_7_31, bmats.A_7_32, bmats.Ax3692, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(bmats.Ax3883, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
