#include "fAx8238.h"
#include "stdafx.h"

inline int fAx8238(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_18_18, bmats.A_18_19, bmats.A_18_20, bmats.A_18_21, bmats.A_18_22, bmats.A_18_23, bmats.A_18_24, bmats.A_18_25, bmats.A_18_26, bmats.A_18_27, bmats.A_18_28, bmats.A_18_29, bmats.A_18_30, bmats.A_18_31, };
    double A_coeffs[14] = {-15, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, };
    matlincomb_double_contiguous(bmats.Ax8238, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
