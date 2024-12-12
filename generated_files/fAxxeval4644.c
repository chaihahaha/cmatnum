#include "stdafx.h"
#include "fAxxeval4644.h"

inline int fAxxeval4644(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3359.data[0][0], 0, sizeof(bmats.Axx3359.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx2225, bmats.Axx2292, bmats.Axx2359, bmats.Axx2427, bmats.Axx2495, bmats.Axx2557, bmats.Axx2625, bmats.Axx2697, bmats.Axx2770, bmats.Axx2842, bmats.Axx2918, bmats.Axx2993, bmats.Axx3071, bmats.Axx3149, bmats.Axx3212, bmats.Axx3358, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3359, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
