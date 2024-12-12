#include "stdafx.h"
#include "fAxxeval8484.h"

inline int fAxxeval8484(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx969.data[0][0], 0, sizeof(bmats.Axx969.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1020, bmats.Axx1641, bmats.Axx1717, bmats.Axx1753, bmats.Axx1841, bmats.Axx2084, bmats.Axx2449, bmats.Axx2465, bmats.Axx2516, bmats.Axx277, bmats.Axx3060, bmats.Axx3177, bmats.Axx70, bmats.Axx900, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx969, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
