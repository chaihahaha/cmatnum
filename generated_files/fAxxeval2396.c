#include "stdafx.h"
#include "fAxxeval2396.h"

inline int fAxxeval2396(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx642.data[0][0], 1);
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.Axx1950, bmats.Axx1963, bmats.Axx621, bmats.Axx637, bmats.Axx638, bmats.Axx639, bmats.Axx640, bmats.Axx641, bmats.Axx643, bmats.Axx644, bmats.Axx647, bmats.Axx648, };
    double A_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx642, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
