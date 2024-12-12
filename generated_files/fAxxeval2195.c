#include "stdafx.h"
#include "fAxxeval2195.h"

inline int fAxxeval2195(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx1845.data[0][0], 1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx224, bmats.Axx408, bmats.Axx478, bmats.Axx507, bmats.Axx509, bmats.Axx511, bmats.Axx513, bmats.Axx515, bmats.Axx517, bmats.Axx519, bmats.Axx521, bmats.Axx539, bmats.Axx565, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1845, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
