#include "stdafx.h"
#include "fAxxeval2486.h"

inline int fAxxeval2486(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx682.data[0][0], 1);
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.Axx1992, bmats.Axx2002, bmats.Axx680, bmats.Axx681, bmats.Axx683, bmats.Axx684, bmats.Axx685, bmats.Axx686, bmats.Axx687, bmats.Axx690, bmats.Axx691, bmats.Axx735, };
    double A_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx682, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
