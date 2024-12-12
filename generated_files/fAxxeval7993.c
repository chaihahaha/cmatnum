#include "stdafx.h"
#include "fAxxeval7993.h"

inline int fAxxeval7993(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2516.data[0][0], 0, sizeof(bmats.Axx2516.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_25_19, bmats.Axx1651, bmats.Axx1920, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx2516, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
