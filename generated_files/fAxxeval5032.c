#include "stdafx.h"
#include "fAxxeval5032.h"

inline int fAxxeval5032(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx824.data[0][0], 0, sizeof(bmats.Axx824.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_3_17, bmats.A_3_18, bmats.A_3_19, bmats.A_3_20, bmats.A_3_23, bmats.A_3_24, bmats.A_3_25, bmats.A_3_26, bmats.A_3_27, bmats.A_3_28, bmats.A_3_29, bmats.A_3_30, bmats.A_3_31, bmats.A_3_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx824, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}