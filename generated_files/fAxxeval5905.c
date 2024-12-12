#include "stdafx.h"
#include "fAxxeval5905.h"

inline int fAxxeval5905(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx378.data[0][0], 0, sizeof(bmats.Axx378.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx1005, bmats.Axx1018, bmats.Axx1524, bmats.Axx1556, bmats.Axx1740, bmats.Axx1747, bmats.Axx2017, bmats.Axx2073, bmats.Axx2099, bmats.Axx2853, bmats.Axx2892, bmats.Axx3007, bmats.Axx3292, bmats.Axx3366, bmats.Axx418, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx378, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
