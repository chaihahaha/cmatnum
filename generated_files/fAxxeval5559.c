#include "stdafx.h"
#include "fAxxeval5559.h"

inline int fAxxeval5559(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1897.data[0][0], 0, sizeof(bmats.Axx1897.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx1011, bmats.Axx1489, bmats.Axx1526, bmats.Axx1609, bmats.Axx1778, bmats.Axx1820, bmats.Axx2071, bmats.Axx2091, bmats.Axx2166, bmats.Axx2304, bmats.Axx2854, bmats.Axx3400, bmats.Axx418, bmats.Axx639, bmats.Axx726, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1897, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
