#include "stdafx.h"
#include "fAxxeval3647.h"

inline int fAxxeval3647(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx2556.data[0][0], 1);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.A_18_8, bmats.Axx2522, };
    double A_coeffs[2] = {1, -1, };
    matlincomb_double_contiguous(bmats.Axx2556, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
