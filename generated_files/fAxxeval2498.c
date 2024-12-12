#include "stdafx.h"
#include "fAxxeval2498.h"

inline int fAxxeval2498(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, -1, &bmats.Axx1979.data[0][0], 1);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.A_9_3, bmats.Axx2018, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx1979, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
