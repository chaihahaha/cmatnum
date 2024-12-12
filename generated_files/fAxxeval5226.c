#include "stdafx.h"
#include "fAxxeval5226.h"

inline int fAxxeval5226(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2156.data[0][0], 0, sizeof(bmats.Axx2156.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_10_17, bmats.A_10_18, bmats.A_10_19, bmats.A_10_20, bmats.A_10_21, bmats.A_10_22, bmats.A_10_23, bmats.A_10_24, bmats.A_10_27, bmats.A_10_28, bmats.A_10_29, bmats.A_10_30, bmats.A_10_31, bmats.A_10_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2156, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
