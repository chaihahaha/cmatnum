#include "stdafx.h"
#include "fAxxeval6011.h"

inline int fAxxeval6011(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2033.data[0][0], 0, sizeof(bmats.Axx2033.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_16_17, bmats.A_16_18, bmats.A_16_21, bmats.A_16_22, bmats.A_16_23, bmats.A_16_24, bmats.A_16_25, bmats.A_16_26, bmats.A_16_27, bmats.A_16_28, bmats.A_16_29, bmats.A_16_30, bmats.A_16_31, bmats.A_16_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2033, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}