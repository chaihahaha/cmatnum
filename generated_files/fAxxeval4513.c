#include "stdafx.h"
#include "fAxxeval4513.h"

inline int fAxxeval4513(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx434.data[0][0], 0, sizeof(bmats.Axx434.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1608, bmats.Axx1796, bmats.Axx1846, bmats.Axx1886, bmats.Axx1934, bmats.Axx1977, bmats.Axx2023, bmats.Axx2142, bmats.Axx624, bmats.Axx674, bmats.Axx683, bmats.Axx723, bmats.Axx777, bmats.Axx825, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx434, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
