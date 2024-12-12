#include "stdafx.h"
#include "fAxxeval3341.h"

inline int fAxxeval3341(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2292.data[0][0], 0, sizeof(bmats.Axx2292.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_22_7, bmats.Axx2250, bmats.Axx2291, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx2292, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
