#include "stdafx.h"
#include "fAxxeval6877.h"

inline int fAxxeval6877(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1967.data[0][0], 0, sizeof(bmats.Axx1967.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_22_17, bmats.A_22_18, bmats.A_22_19, bmats.A_22_20, bmats.A_22_21, bmats.A_22_22, bmats.A_22_23, bmats.A_22_24, bmats.A_22_27, bmats.A_22_28, bmats.A_22_29, bmats.A_22_30, bmats.A_22_31, bmats.A_22_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1967, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
