#include "stdafx.h"
#include "fAxxeval8345.h"

inline int fAxxeval8345(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2838.data[0][0], 0, sizeof(bmats.Axx2838.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1120, bmats.Axx1183, bmats.Axx1243, bmats.Axx1290, bmats.Axx1337, bmats.Axx1389, bmats.Axx1415, bmats.Axx1467, bmats.Axx1796, bmats.Axx1814, bmats.Axx357, bmats.Axx358, bmats.Axx926, bmats.Axx927, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2838, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}