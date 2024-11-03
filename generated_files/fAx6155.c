#include "fAx6155.h"
#include "stdafx.h"

inline int fAx6155(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_20_17, bmats.A_20_19, bmats.A_20_22, bmats.A_20_25, bmats.A_20_27, bmats.A_20_31, };
    double A_coeffs[6] = {-1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax6155, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
