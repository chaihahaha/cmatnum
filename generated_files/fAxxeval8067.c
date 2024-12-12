#include "stdafx.h"
#include "fAxxeval8067.h"

inline int fAxxeval8067(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1799.data[0][0], 0, sizeof(bmats.Axx1799.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx108, bmats.Axx1470, bmats.Axx1473, bmats.Axx1476, bmats.Axx1593, bmats.Axx1611, bmats.Axx1826, bmats.Axx2159, bmats.Axx2618, bmats.Axx3156, bmats.Axx317, bmats.Axx3220, bmats.Axx3380, bmats.Axx359, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1799, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
