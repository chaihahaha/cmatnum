#include "stdafx.h"
#include "fAxxeval1590.h"

inline int fAxxeval1590(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx1543.data[0][0], 1);
    int n_A_mats = 1;
    double_cmat A_mats[1] = {bmats.Axx1545, };
    double A_coeffs[1] = {1, };
    matlincomb_double_contiguous(bmats.Axx1543, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}