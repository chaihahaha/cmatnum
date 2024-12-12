#include "stdafx.h"
#include "fAxxeval2276.h"

inline int fAxxeval2276(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx904.data[0][0], 1);
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.Axx1891, bmats.Axx1901, bmats.Axx585, bmats.Axx586, bmats.Axx587, bmats.Axx588, bmats.Axx591, bmats.Axx592, bmats.Axx593, bmats.Axx594, bmats.Axx595, bmats.Axx596, };
    double A_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx904, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
