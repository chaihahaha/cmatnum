#include "stdafx.h"
#include "fAxxeval1736.h"

inline int fAxxeval1736(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx828.data[0][0], 1);
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.Axx1633, bmats.Axx202, bmats.Axx203, bmats.Axx204, bmats.Axx205, bmats.Axx206, bmats.Axx207, bmats.Axx208, bmats.Axx209, bmats.Axx210, bmats.Axx211, bmats.Axx229, };
    double A_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx828, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
