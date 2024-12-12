#include "stdafx.h"
#include "fAxxeval2405.h"

inline int fAxxeval2405(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx618.data[0][0], 1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx1631, bmats.Axx492, bmats.Axx493, bmats.Axx552, bmats.Axx553, bmats.Axx606, bmats.Axx622, bmats.Axx624, bmats.Axx626, bmats.Axx628, bmats.Axx630, bmats.Axx647, bmats.Axx660, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx618, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
