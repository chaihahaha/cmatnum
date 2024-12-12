#include "stdafx.h"
#include "fAxxeval4633.h"

inline int fAxxeval4633(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3350.data[0][0], 0, sizeof(bmats.Axx3350.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx2217, bmats.Axx2276, bmats.Axx2350, bmats.Axx2418, bmats.Axx2486, bmats.Axx2549, bmats.Axx2611, bmats.Axx2691, bmats.Axx2762, bmats.Axx2837, bmats.Axx2901, bmats.Axx2981, bmats.Axx3065, bmats.Axx3144, bmats.Axx3230, bmats.Axx3347, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3350, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
