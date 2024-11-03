#include "fAx6602.h"
#include "stdafx.h"

inline int fAx6602(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 10;
    double_cmat A_mats[10] = {bmats.A_17_20, bmats.A_17_21, bmats.A_17_22, bmats.A_17_23, bmats.A_17_24, bmats.A_17_25, bmats.A_17_26, bmats.A_17_27, bmats.A_17_28, bmats.A_17_29, };
    double A_coeffs[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax6602, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
