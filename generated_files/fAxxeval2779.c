#include "stdafx.h"
#include "fAxxeval2779.h"

inline int fAxxeval2779(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx810.data[0][0], 1);
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.Axx2101, bmats.Axx2111, bmats.Axx802, bmats.Axx803, bmats.Axx804, bmats.Axx805, bmats.Axx808, bmats.Axx809, bmats.Axx811, bmats.Axx812, bmats.Axx813, bmats.Axx857, };
    double A_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx810, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
