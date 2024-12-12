#include "stdafx.h"
#include "fAxxeval3349.h"

inline int fAxxeval3349(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2298.data[0][0], 0, sizeof(bmats.Axx2298.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_22_11, bmats.Axx2258, bmats.Axx2297, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx2298, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
