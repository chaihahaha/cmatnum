#include "stdafx.h"
#include "fAxxeval6352.h"

inline int fAxxeval6352(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2042.data[0][0], 0, sizeof(bmats.Axx2042.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1592, bmats.Axx1608, bmats.Axx1796, bmats.Axx1846, bmats.Axx1886, bmats.Axx1934, bmats.Axx1977, bmats.Axx2023, bmats.Axx2142, bmats.Axx2608, bmats.Axx674, bmats.Axx683, bmats.Axx723, bmats.Axx825, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2042, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
