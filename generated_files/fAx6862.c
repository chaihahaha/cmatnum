#include "fAx6862.h"

inline int fAx6862(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 11;
    double_cmat A_mats[11] = {bmats.A_25_17, bmats.A_25_18, bmats.A_25_19, bmats.A_25_22, bmats.A_25_23, bmats.A_25_24, bmats.A_25_26, bmats.A_25_27, bmats.A_25_28, bmats.A_25_29, bmats.A_25_30, };
    double A_coeffs[11] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax6862, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
