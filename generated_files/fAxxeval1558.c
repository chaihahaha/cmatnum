#include "stdafx.h"
#include "fAxxeval1558.h"

inline int fAxxeval1558(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx1490.data[0][0], 1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx1533, bmats.Axx66, bmats.Axx67, bmats.Axx74, bmats.Axx75, bmats.Axx82, bmats.Axx83, bmats.Axx86, bmats.Axx87, bmats.Axx90, bmats.Axx91, bmats.Axx94, bmats.Axx95, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1490, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
