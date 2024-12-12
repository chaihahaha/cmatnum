#include "stdafx.h"
#include "fAxxeval4869.h"

inline int fAxxeval4869(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx593.data[0][0], 0, sizeof(bmats.Axx593.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_5_17, bmats.A_5_18, bmats.A_5_19, bmats.A_5_20, bmats.A_5_21, bmats.A_5_22, bmats.A_5_23, bmats.A_5_24, bmats.A_5_27, bmats.A_5_28, bmats.A_5_29, bmats.A_5_30, bmats.A_5_31, bmats.A_5_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx593, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
