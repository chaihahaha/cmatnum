#include "stdafx.h"
#include "fAxxeval1718.h"

inline int fAxxeval1718(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx1591.data[0][0], 1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx1625, bmats.Axx179, bmats.Axx180, bmats.Axx183, bmats.Axx184, bmats.Axx187, bmats.Axx188, bmats.Axx191, bmats.Axx192, bmats.Axx195, bmats.Axx196, bmats.Axx198, bmats.Axx199, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1591, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
