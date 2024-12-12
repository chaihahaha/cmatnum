#include "stdafx.h"
#include "fAxxeval7784.h"

inline int fAxxeval7784(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1005.data[0][0], 0, sizeof(bmats.Axx1005.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1067, bmats.Axx1123, bmats.Axx1186, bmats.Axx1246, bmats.Axx1293, bmats.Axx1340, bmats.Axx1387, bmats.Axx1418, bmats.Axx1431, bmats.Axx1437, bmats.Axx249, bmats.Axx354, bmats.Axx355, bmats.Axx766, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1005, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
