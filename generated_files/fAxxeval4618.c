#include "stdafx.h"
#include "fAxxeval4618.h"

inline int fAxxeval4618(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3337.data[0][0], 0, sizeof(bmats.Axx3337.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx2227, bmats.Axx2294, bmats.Axx2361, bmats.Axx2429, bmats.Axx2497, bmats.Axx2559, bmats.Axx2629, bmats.Axx2703, bmats.Axx2774, bmats.Axx2844, bmats.Axx2915, bmats.Axx2999, bmats.Axx3077, bmats.Axx3153, bmats.Axx3220, bmats.Axx3331, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3337, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
