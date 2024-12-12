#include "stdafx.h"
#include "fAxxeval1956.h"

inline int fAxxeval1956(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx1684.data[0][0], 1);
    int n_A_mats = 9;
    double_cmat A_mats[9] = {bmats.Axx1726, bmats.Axx1727, bmats.Axx1730, bmats.Axx1732, bmats.Axx297, bmats.Axx308, bmats.Axx311, bmats.Axx375, bmats.Axx378, };
    double A_coeffs[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1684, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
