#include "stdafx.h"
#include "fAxxeval6125.h"

inline int fAxxeval6125(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2089.data[0][0], 0, sizeof(bmats.Axx2089.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx1613, bmats.Axx1703, bmats.Axx1747, bmats.Axx1750, bmats.Axx184, bmats.Axx2179, bmats.Axx2268, bmats.Axx2475, bmats.Axx2788, bmats.Axx3160, bmats.Axx3250, bmats.Axx3392, bmats.Axx3411, bmats.Axx594, bmats.Axx595, bmats.Axx726, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2089, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
