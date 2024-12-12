#include "stdafx.h"
#include "fAxxeval8350.h"

inline int fAxxeval8350(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3118.data[0][0], 0, sizeof(bmats.Axx3118.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx151, bmats.Axx1513, bmats.Axx1674, bmats.Axx1724, bmats.Axx1937, bmats.Axx2450, bmats.Axx2718, bmats.Axx488, bmats.Axx499, bmats.Axx537, bmats.Axx575, bmats.Axx627, bmats.Axx676, bmats.Axx846, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3118, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
