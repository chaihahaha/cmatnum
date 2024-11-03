#include "fAx6138.h"
#include "stdafx.h"

inline int fAx6138(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 9;
    double_cmat A_mats[9] = {bmats.A_20_17, bmats.A_20_22, bmats.A_20_23, bmats.A_20_24, bmats.A_20_25, bmats.A_20_26, bmats.A_20_27, bmats.A_20_31, bmats.A_20_32, };
    double A_coeffs[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax6138, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
