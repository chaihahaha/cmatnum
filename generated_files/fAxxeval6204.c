#include "stdafx.h"
#include "fAxxeval6204.h"

inline int fAxxeval6204(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2091.data[0][0], 0, sizeof(bmats.Axx2091.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx1494, bmats.Axx1670, bmats.Axx1956, bmats.Axx2102, bmats.Axx2133, bmats.Axx2308, bmats.Axx2710, bmats.Axx2890, bmats.Axx2892, bmats.Axx3049, bmats.Axx3200, bmats.Axx3253, bmats.Axx3401, bmats.Axx517, bmats.Axx531, bmats.Axx892, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2091, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
