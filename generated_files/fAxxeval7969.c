#include "stdafx.h"
#include "fAxxeval7969.h"

inline int fAxxeval7969(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1692.data[0][0], 0, sizeof(bmats.Axx1692.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1188, bmats.Axx1189, bmats.Axx1287, bmats.Axx1295, bmats.Axx1296, bmats.Axx1382, bmats.Axx1439, bmats.Axx1461, bmats.Axx1465, bmats.Axx1600, bmats.Axx351, bmats.Axx352, bmats.Axx931, bmats.Axx932, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1692, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}