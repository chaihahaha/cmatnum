#include "stdafx.h"
#include "fAxxeval2519.h"

inline int fAxxeval2519(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx638.data[0][0], 0, sizeof(bmats.Axx638.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_9_1, bmats.A_9_10, bmats.A_9_13, bmats.A_9_14, bmats.A_9_15, bmats.A_9_16, bmats.A_9_2, bmats.A_9_3, bmats.A_9_4, bmats.A_9_5, bmats.A_9_6, bmats.A_9_7, bmats.A_9_8, bmats.A_9_9, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx638, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}