#include "stdafx.h"
#include "fAxxeval7159.h"

inline int fAxxeval7159(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3121.data[0][0], 0, sizeof(bmats.Axx3121.data[0][0])*BL*BL);
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.Axx1150, bmats.Axx1283, bmats.Axx1287, bmats.Axx16, bmats.Axx1857, bmats.Axx2042, bmats.Axx2448, bmats.Axx2795, bmats.Axx334, bmats.Axx707, bmats.Axx894, bmats.Axx989, };
    double A_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3121, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
