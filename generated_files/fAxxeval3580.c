#include "stdafx.h"
#include "fAxxeval3580.h"

inline int fAxxeval3580(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx2500.data[0][0], 1);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.A_19_12, bmats.Axx2464, };
    double A_coeffs[2] = {1, -1, };
    matlincomb_double_contiguous(bmats.Axx2500, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
