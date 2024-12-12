#include "stdafx.h"
#include "fAxxeval4241.h"

inline int fAxxeval4241(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3080.data[0][0], 0, sizeof(bmats.Axx3080.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_28_1, bmats.A_28_10, bmats.A_28_13, bmats.A_28_14, bmats.A_28_15, bmats.A_28_16, bmats.A_28_2, bmats.A_28_3, bmats.A_28_4, bmats.A_28_5, bmats.A_28_6, bmats.A_28_7, bmats.A_28_8, bmats.A_28_9, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3080, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
