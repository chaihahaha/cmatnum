#include "stdafx.h"
#include "fAxxeval5289.h"

inline int fAxxeval5289(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2134.data[0][0], 0, sizeof(bmats.Axx2134.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx1000, bmats.Axx1005, bmats.Axx1643, bmats.Axx1653, bmats.Axx1737, bmats.Axx1802, bmats.Axx2067, bmats.Axx2854, bmats.Axx3250, bmats.Axx3400, bmats.Axx368, bmats.Axx475, bmats.Axx667, bmats.Axx726, bmats.Axx727, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2134, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}