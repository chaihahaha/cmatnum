#include "stdafx.h"
#include "fAxxeval5830.h"

inline int fAxxeval5830(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2639.data[0][0], 0, sizeof(bmats.Axx2639.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_12_17, bmats.Axx2164, bmats.Axx380, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx2639, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
