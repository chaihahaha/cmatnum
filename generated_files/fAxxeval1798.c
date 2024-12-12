#include "stdafx.h"
#include "fAxxeval1798.h"

inline int fAxxeval1798(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx1667.data[0][0], 1);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx279, bmats.Axx280, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx1667, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
