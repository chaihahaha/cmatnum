#include "stdafx.h"
#include "fAxxeval2881.h"

inline int fAxxeval2881(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx834.data[0][0], 1);
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.Axx2130, bmats.Axx2144, bmats.Axx842, bmats.Axx843, bmats.Axx844, bmats.Axx845, bmats.Axx846, bmats.Axx847, bmats.Axx848, bmats.Axx849, bmats.Axx852, bmats.Axx853, };
    double A_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx834, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
