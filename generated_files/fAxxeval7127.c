#include "stdafx.h"
#include "fAxxeval7127.h"

inline int fAxxeval7127(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx445.data[0][0], 0, sizeof(bmats.Axx445.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_20_17, bmats.A_20_18, bmats.A_20_19, bmats.A_20_20, bmats.A_20_21, bmats.A_20_22, bmats.A_20_25, bmats.A_20_26, bmats.A_20_27, bmats.A_20_28, bmats.A_20_29, bmats.A_20_30, bmats.A_20_31, bmats.A_20_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx445, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}