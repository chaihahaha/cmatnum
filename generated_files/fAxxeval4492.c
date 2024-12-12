#include "stdafx.h"
#include "fAxxeval4492.h"

inline int fAxxeval4492(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx988.data[0][0], 0, sizeof(bmats.Axx988.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx11, bmats.Axx1580, bmats.Axx1784, bmats.Axx1828, bmats.Axx1921, bmats.Axx1939, bmats.Axx1987, bmats.Axx2058, bmats.Axx2076, bmats.Axx2088, bmats.Axx471, bmats.Axx501, bmats.Axx559, bmats.Axx826, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx988, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
