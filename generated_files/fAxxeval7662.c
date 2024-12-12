#include "stdafx.h"
#include "fAxxeval7662.h"

inline int fAxxeval7662(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2897.data[0][0], 0, sizeof(bmats.Axx2897.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1090, bmats.Axx1091, bmats.Axx1138, bmats.Axx1202, bmats.Axx1256, bmats.Axx1306, bmats.Axx1347, bmats.Axx1395, bmats.Axx1397, bmats.Axx1403, bmats.Axx1771, bmats.Axx2606, bmats.Axx331, bmats.Axx332, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2897, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
