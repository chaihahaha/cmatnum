#include "stdafx.h"
#include "fAxxeval1838.h"

inline int fAxxeval1838(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1691.data[0][0], 0, sizeof(bmats.Axx1691.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_29_17, bmats.A_29_18, bmats.A_29_21, bmats.A_29_22, bmats.A_29_23, bmats.A_29_24, bmats.A_29_25, bmats.A_29_26, bmats.A_29_27, bmats.A_29_28, bmats.A_29_29, bmats.A_29_30, bmats.A_29_31, bmats.A_29_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1691, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}