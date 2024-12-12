#include "stdafx.h"
#include "fAxxeval5376.h"

inline int fAxxeval5376(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2854.data[0][0], 0, sizeof(bmats.Axx2854.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx1003, bmats.Axx1006, bmats.Axx1603, bmats.Axx1663, bmats.Axx1666, bmats.Axx1870, bmats.Axx2071, bmats.Axx2141, bmats.Axx2208, bmats.Axx3282, bmats.Axx3292, bmats.Axx3359, bmats.Axx696, bmats.Axx708, bmats.Axx945, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2854, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
