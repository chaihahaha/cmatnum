#include "stdafx.h"
#include "fAxxeval3627.h"

inline int fAxxeval3627(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx1659.data[0][0], 1);
    int n_A_mats = 1;
    double_cmat A_mats[1] = {bmats.Axx238, };
    double A_coeffs[1] = {1, };
    matlincomb_double_contiguous(bmats.Axx1659, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}