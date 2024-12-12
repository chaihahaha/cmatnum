#include "stdafx.h"
#include "fAxxeval3721.h"

inline int fAxxeval3721(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2623.data[0][0], 0, sizeof(bmats.Axx2623.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_26_5, bmats.Axx2579, bmats.Axx2622, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx2623, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
