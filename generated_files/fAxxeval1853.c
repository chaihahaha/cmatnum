#include "stdafx.h"
#include "fAxxeval1853.h"

inline int fAxxeval1853(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx281.data[0][0], 0, sizeof(bmats.Axx281.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_29_17, bmats.A_29_18, bmats.A_29_19, bmats.A_29_20, bmats.A_29_21, bmats.A_29_22, bmats.A_29_23, bmats.A_29_24, bmats.A_29_25, bmats.A_29_26, bmats.A_29_29, bmats.A_29_30, bmats.A_29_31, bmats.A_29_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx281, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}