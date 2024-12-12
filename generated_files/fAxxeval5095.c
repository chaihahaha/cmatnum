#include "stdafx.h"
#include "fAxxeval5095.h"

inline int fAxxeval5095(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2852.data[0][0], 0, sizeof(bmats.Axx2852.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx1001, bmats.Axx1703, bmats.Axx1748, bmats.Axx1870, bmats.Axx1907, bmats.Axx192, bmats.Axx2168, bmats.Axx2641, bmats.Axx3240, bmats.Axx3255, bmats.Axx3343, bmats.Axx538, bmats.Axx586, bmats.Axx998, bmats.Axx999, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2852, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
