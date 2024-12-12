#include "stdafx.h"
#include "fAxxeval7162.h"

inline int fAxxeval7162(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2493.data[0][0], 0, sizeof(bmats.Axx2493.data[0][0])*BL*BL);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx1150, bmats.Axx1274, bmats.Axx1280, bmats.Axx1287, bmats.Axx16, bmats.Axx1857, bmats.Axx2042, bmats.Axx2448, bmats.Axx2795, bmats.Axx334, bmats.Axx707, bmats.Axx894, bmats.Axx989, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2493, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
