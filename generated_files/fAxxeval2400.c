#include "stdafx.h"
#include "fAxxeval2400.h"

inline int fAxxeval2400(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx648.data[0][0], 0, sizeof(bmats.Axx648.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1631, bmats.Axx492, bmats.Axx493, bmats.Axx552, bmats.Axx606, bmats.Axx618, bmats.Axx622, bmats.Axx624, bmats.Axx626, bmats.Axx628, bmats.Axx630, bmats.Axx632, bmats.Axx634, bmats.Axx647, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx648, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
