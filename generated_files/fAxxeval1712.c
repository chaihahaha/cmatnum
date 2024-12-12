#include "stdafx.h"
#include "fAxxeval1712.h"

inline int fAxxeval1712(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1626.data[0][0], 0, sizeof(bmats.Axx1626.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1591, bmats.Axx1625, bmats.Axx179, bmats.Axx180, bmats.Axx183, bmats.Axx184, bmats.Axx187, bmats.Axx188, bmats.Axx191, bmats.Axx192, bmats.Axx195, bmats.Axx196, bmats.Axx231, bmats.Axx232, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1626, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
