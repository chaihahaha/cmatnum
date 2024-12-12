#include "stdafx.h"
#include "fAxxeval8349.h"

inline int fAxxeval8349(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1659.data[0][0], 0, sizeof(bmats.Axx1659.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1513, bmats.Axx1674, bmats.Axx1724, bmats.Axx1782, bmats.Axx2450, bmats.Axx2718, bmats.Axx3295, bmats.Axx488, bmats.Axx499, bmats.Axx537, bmats.Axx575, bmats.Axx627, bmats.Axx676, bmats.Axx846, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1659, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
