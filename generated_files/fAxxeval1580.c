#include "stdafx.h"
#include "fAxxeval1580.h"

inline int fAxxeval1580(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx78.data[0][0], 0, sizeof(bmats.Axx78.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_31_17, bmats.A_31_18, bmats.A_31_19, bmats.A_31_20, bmats.A_31_21, bmats.A_31_22, bmats.A_31_23, bmats.A_31_24, bmats.A_31_25, bmats.A_31_26, bmats.A_31_27, bmats.A_31_28, bmats.A_31_29, bmats.A_31_30, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx78, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}