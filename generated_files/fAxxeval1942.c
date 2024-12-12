#include "stdafx.h"
#include "fAxxeval1942.h"

inline int fAxxeval1942(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx372.data[0][0], 1);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx1713, bmats.Axx1743, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx372, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
