#include "stdafx.h"
#include "fAxxeval6387.h"

inline int fAxxeval6387(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1973.data[0][0], 0, sizeof(bmats.Axx1973.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1548, bmats.Axx1614, bmats.Axx1627, bmats.Axx1684, bmats.Axx1768, bmats.Axx1831, bmats.Axx1848, bmats.Axx1917, bmats.Axx1985, bmats.Axx27, bmats.Axx511, bmats.Axx676, bmats.Axx722, bmats.Axx849, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1973, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}