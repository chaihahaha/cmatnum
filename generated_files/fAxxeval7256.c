#include "stdafx.h"
#include "fAxxeval7256.h"

inline int fAxxeval7256(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx917.data[0][0], 0, sizeof(bmats.Axx917.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1134, bmats.Axx1197, bmats.Axx1252, bmats.Axx1265, bmats.Axx1267, bmats.Axx1269, bmats.Axx1271, bmats.Axx1273, bmats.Axx1276, bmats.Axx1279, bmats.Axx2434, bmats.Axx34, bmats.Axx340, bmats.Axx341, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx917, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}