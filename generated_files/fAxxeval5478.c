#include "stdafx.h"
#include "fAxxeval5478.h"

inline int fAxxeval5478(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1940.data[0][0], 0, sizeof(bmats.Axx1940.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_7_17, bmats.A_7_18, bmats.A_7_19, bmats.A_7_20, bmats.A_7_23, bmats.A_7_24, bmats.A_7_25, bmats.A_7_26, bmats.A_7_27, bmats.A_7_28, bmats.A_7_29, bmats.A_7_30, bmats.A_7_31, bmats.A_7_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1940, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}