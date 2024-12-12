#include "stdafx.h"
#include "fAxxeval6354.h"

inline int fAxxeval6354(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx688.data[0][0], 0, sizeof(bmats.Axx688.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1592, bmats.Axx1608, bmats.Axx1796, bmats.Axx1846, bmats.Axx1886, bmats.Axx1934, bmats.Axx2142, bmats.Axx2608, bmats.Axx624, bmats.Axx674, bmats.Axx683, bmats.Axx723, bmats.Axx777, bmats.Axx825, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx688, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
