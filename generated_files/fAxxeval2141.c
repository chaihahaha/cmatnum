#include "stdafx.h"
#include "fAxxeval2141.h"

inline int fAxxeval2141(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx474.data[0][0], 1);
    int n_A_mats = 1;
    double_cmat A_mats[1] = {bmats.Axx1842, };
    double A_coeffs[1] = {1, };
    matlincomb_double_contiguous(bmats.Axx474, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
