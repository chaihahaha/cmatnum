#include "stdafx.h"
#include "fAxxeval4916.h"

inline int fAxxeval4916(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1561.data[0][0], 0, sizeof(bmats.Axx1561.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx1521, bmats.Axx1671, bmats.Axx1824, bmats.Axx1896, bmats.Axx1942, bmats.Axx2132, bmats.Axx2473, bmats.Axx2540, bmats.Axx2782, bmats.Axx3242, bmats.Axx3349, bmats.Axx3399, bmats.Axx824, bmats.Axx993, bmats.Axx996, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1561, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
