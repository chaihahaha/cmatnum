#include "stdafx.h"
#include "fAxxeval4322.h"

inline int fAxxeval4322(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3152.data[0][0], 0, sizeof(bmats.Axx3152.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_27_1, bmats.A_27_11, bmats.A_27_12, bmats.A_27_13, bmats.A_27_14, bmats.A_27_15, bmats.A_27_16, bmats.A_27_2, bmats.A_27_3, bmats.A_27_4, bmats.A_27_5, bmats.A_27_6, bmats.A_27_7, bmats.A_27_8, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3152, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}