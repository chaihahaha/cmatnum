#include "stdafx.h"
#include "fAxxeval4961.h"

inline int fAxxeval4961(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1726.data[0][0], 0, sizeof(bmats.Axx1726.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_4_17, bmats.A_4_18, bmats.A_4_19, bmats.A_4_20, bmats.A_4_21, bmats.A_4_22, bmats.A_4_23, bmats.A_4_24, bmats.A_4_25, bmats.A_4_26, bmats.A_4_29, bmats.A_4_30, bmats.A_4_31, bmats.A_4_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1726, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
