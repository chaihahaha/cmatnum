#include "stdafx.h"
#include "fAxxeval7678.h"

inline int fAxxeval7678(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2065.data[0][0], 0, sizeof(bmats.Axx2065.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_17_17, bmats.A_17_18, bmats.A_17_19, bmats.A_17_20, bmats.A_17_21, bmats.A_17_22, bmats.A_17_23, bmats.A_17_24, bmats.A_17_25, bmats.A_17_26, bmats.A_17_27, bmats.A_17_28, bmats.A_17_31, bmats.A_17_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2065, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}