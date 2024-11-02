#include "fAx6947.h"

inline int fAx6947(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 9;
    double_cmat A_mats[9] = {bmats.A_24_17, bmats.A_24_21, bmats.A_24_22, bmats.A_24_23, bmats.A_24_25, bmats.A_24_29, bmats.A_24_30, bmats.A_24_31, bmats.A_24_32, };
    double A_coeffs[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax6947, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
