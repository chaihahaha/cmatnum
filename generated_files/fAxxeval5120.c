#include "stdafx.h"
#include "fAxxeval5120.h"

inline int fAxxeval5120(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx475.data[0][0], 0, sizeof(bmats.Axx475.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_2_17, bmats.A_2_18, bmats.A_2_19, bmats.A_2_20, bmats.A_2_23, bmats.A_2_24, bmats.A_2_25, bmats.A_2_26, bmats.A_2_27, bmats.A_2_28, bmats.A_2_29, bmats.A_2_30, bmats.A_2_31, bmats.A_2_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx475, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}