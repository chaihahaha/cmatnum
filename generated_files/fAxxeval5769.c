#include "stdafx.h"
#include "fAxxeval5769.h"

inline int fAxxeval5769(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1496.data[0][0], 0, sizeof(bmats.Axx1496.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_13_17, bmats.A_13_18, bmats.A_13_19, bmats.A_13_20, bmats.A_13_21, bmats.A_13_22, bmats.A_13_23, bmats.A_13_24, bmats.A_13_25, bmats.A_13_26, bmats.A_13_29, bmats.A_13_30, bmats.A_13_31, bmats.A_13_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1496, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
