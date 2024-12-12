#include "stdafx.h"
#include "fAxxeval7414.h"

inline int fAxxeval7414(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2823.data[0][0], 0, sizeof(bmats.Axx2823.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1077, bmats.Axx1078, bmats.Axx1136, bmats.Axx1200, bmats.Axx1254, bmats.Axx1302, bmats.Axx1313, bmats.Axx1316, bmats.Axx1325, bmats.Axx1329, bmats.Axx3005, bmats.Axx3123, bmats.Axx327, bmats.Axx328, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2823, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
