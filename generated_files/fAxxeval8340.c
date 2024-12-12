#include "stdafx.h"
#include "fAxxeval8340.h"

inline int fAxxeval8340(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2594.data[0][0], 0, sizeof(bmats.Axx2594.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1120, bmats.Axx1183, bmats.Axx1243, bmats.Axx1290, bmats.Axx1337, bmats.Axx1389, bmats.Axx1415, bmats.Axx1441, bmats.Axx1467, bmats.Axx1481, bmats.Axx1796, bmats.Axx1814, bmats.Axx926, bmats.Axx927, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2594, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
