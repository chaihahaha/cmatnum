#include "stdafx.h"
#include "fAxxeval2300.h"

inline int fAxxeval2300(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1921.data[0][0], 0, sizeof(bmats.Axx1921.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_3_1, bmats.A_3_10, bmats.A_3_11, bmats.A_3_12, bmats.A_3_13, bmats.A_3_14, bmats.A_3_15, bmats.A_3_16, bmats.A_3_2, bmats.A_3_3, bmats.A_3_4, bmats.A_3_7, bmats.A_3_8, bmats.A_3_9, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1921, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}