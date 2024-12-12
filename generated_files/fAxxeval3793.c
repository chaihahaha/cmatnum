#include "stdafx.h"
#include "fAxxeval3793.h"

inline int fAxxeval3793(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx2686.data[0][0], 1);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.A_25_1, bmats.Axx2647, };
    double A_coeffs[2] = {1, -1, };
    matlincomb_double_contiguous(bmats.Axx2686, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
