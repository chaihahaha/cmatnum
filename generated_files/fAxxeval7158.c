#include "stdafx.h"
#include "fAxxeval7158.h"

inline int fAxxeval7158(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2593.data[0][0], 0, sizeof(bmats.Axx2593.data[0][0])*BL*BL);
    int n_A_mats = 11;
    double_cmat A_mats[11] = {bmats.Axx1150, bmats.Axx1280, bmats.Axx1283, bmats.Axx1287, bmats.Axx2042, bmats.Axx2448, bmats.Axx2795, bmats.Axx334, bmats.Axx707, bmats.Axx894, bmats.Axx989, };
    double A_coeffs[11] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2593, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
