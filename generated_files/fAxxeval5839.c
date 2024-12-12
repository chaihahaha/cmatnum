#include "stdafx.h"
#include "fAxxeval5839.h"

inline int fAxxeval5839(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1995.data[0][0], 0, sizeof(bmats.Axx1995.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_12_17, bmats.A_12_18, bmats.A_12_19, bmats.A_12_20, bmats.A_12_21, bmats.A_12_22, bmats.A_12_25, bmats.A_12_26, bmats.A_12_27, bmats.A_12_28, bmats.A_12_29, bmats.A_12_30, bmats.A_12_31, bmats.A_12_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1995, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
