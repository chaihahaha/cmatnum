#include "stdafx.h"
#include "fAxxeval2979.h"

inline int fAxxeval2979(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx876.data[0][0], 1);
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.Axx476, bmats.Axx831, bmats.Axx871, bmats.Axx872, bmats.Axx873, bmats.Axx874, bmats.Axx875, bmats.Axx877, bmats.Axx878, bmats.Axx880, bmats.Axx882, bmats.Axx883, };
    double A_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx876, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
