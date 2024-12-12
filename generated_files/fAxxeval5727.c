#include "stdafx.h"
#include "fAxxeval5727.h"

inline int fAxxeval5727(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2308.data[0][0], 0, sizeof(bmats.Axx2308.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx1015, bmats.Axx1489, bmats.Axx1524, bmats.Axx1694, bmats.Axx1728, bmats.Axx2073, bmats.Axx2087, bmats.Axx2123, bmats.Axx2302, bmats.Axx2304, bmats.Axx2638, bmats.Axx3376, bmats.Axx475, bmats.Axx620, bmats.Axx726, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2308, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
