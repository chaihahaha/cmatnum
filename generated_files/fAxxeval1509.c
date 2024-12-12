#include "stdafx.h"
#include "fAxxeval1509.h"

inline int fAxxeval1509(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx69.data[0][0], 1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx1486, bmats.Axx1489, bmats.Axx1490, bmats.Axx1492, bmats.Axx1493, bmats.Axx1494, bmats.Axx1495, bmats.Axx1496, bmats.Axx1498, bmats.Axx1499, bmats.Axx64, bmats.Axx76, bmats.Axx80, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx69, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
