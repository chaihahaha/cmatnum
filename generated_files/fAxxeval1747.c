#include "stdafx.h"
#include "fAxxeval1747.h"

inline int fAxxeval1747(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx206.data[0][0], 0, sizeof(bmats.Axx206.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_15_1, bmats.A_15_10, bmats.A_15_11, bmats.A_15_12, bmats.A_15_13, bmats.A_15_14, bmats.A_15_15, bmats.A_15_16, bmats.A_15_2, bmats.A_15_3, bmats.A_15_4, bmats.A_15_7, bmats.A_15_8, bmats.A_15_9, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx206, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
