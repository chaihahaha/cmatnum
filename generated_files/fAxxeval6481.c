#include "stdafx.h"
#include "fAxxeval6481.h"

inline int fAxxeval6481(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1902.data[0][0], 0, sizeof(bmats.Axx1902.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1579, bmats.Axx1604, bmats.Axx173, bmats.Axx1787, bmats.Axx1923, bmats.Axx1947, bmats.Axx2001, bmats.Axx2031, bmats.Axx421, bmats.Axx440, bmats.Axx452, bmats.Axx456, bmats.Axx533, bmats.Axx784, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1902, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}