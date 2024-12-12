#include "stdafx.h"
#include "fAxxeval4842.h"

inline int fAxxeval4842(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1944.data[0][0], 0, sizeof(bmats.Axx1944.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx1515, bmats.Axx1671, bmats.Axx1778, bmats.Axx1954, bmats.Axx1980, bmats.Axx1984, bmats.Axx3355, bmats.Axx3380, bmats.Axx3391, bmats.Axx3392, bmats.Axx3411, bmats.Axx394, bmats.Axx425, bmats.Axx531, bmats.Axx834, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1944, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
