#include "stdafx.h"
#include "fAxxeval2285.h"

inline int fAxxeval2285(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx1887.data[0][0], 1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx1911, bmats.Axx541, bmats.Axx542, bmats.Axx568, bmats.Axx569, bmats.Axx572, bmats.Axx573, bmats.Axx575, bmats.Axx576, bmats.Axx579, bmats.Axx580, bmats.Axx614, bmats.Axx615, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1887, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
