#include "fAx2661.h"

inline int fAx2661(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_11_17, bmats.A_11_18, bmats.A_11_19, bmats.A_11_20, bmats.A_11_21, bmats.A_11_22, bmats.A_11_23, bmats.A_11_24, bmats.A_11_25, bmats.A_11_27, bmats.A_11_28, bmats.A_11_29, bmats.A_11_30, bmats.A_11_32, bmats.Ax2598, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(bmats.Ax2661, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
