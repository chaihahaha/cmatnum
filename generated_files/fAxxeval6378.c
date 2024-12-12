#include "stdafx.h"
#include "fAxxeval6378.h"

inline int fAxxeval6378(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2593.data[0][0], 0, sizeof(bmats.Axx2593.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1568, bmats.Axx1610, bmats.Axx1753, bmats.Axx1810, bmats.Axx1895, bmats.Axx1903, bmats.Axx2025, bmats.Axx31, bmats.Axx519, bmats.Axx555, bmats.Axx565, bmats.Axx660, bmats.Axx765, bmats.Axx877, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2593, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
