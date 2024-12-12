#include "stdafx.h"
#include "fAxxeval2192.h"

inline int fAxxeval2192(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1875.data[0][0], 0, sizeof(bmats.Axx1875.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1845, bmats.Axx224, bmats.Axx408, bmats.Axx478, bmats.Axx511, bmats.Axx513, bmats.Axx515, bmats.Axx517, bmats.Axx519, bmats.Axx521, bmats.Axx523, bmats.Axx525, bmats.Axx539, bmats.Axx565, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1875, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
