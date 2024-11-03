#include "fAx6953.h"
#include "stdafx.h"

inline int fAx6953(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 8;
    double_cmat A_mats[8] = {bmats.A_24_17, bmats.A_24_19, bmats.A_24_23, bmats.A_24_25, bmats.A_24_29, bmats.A_24_30, bmats.A_24_31, bmats.A_24_32, };
    double A_coeffs[8] = {-1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax6953, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
