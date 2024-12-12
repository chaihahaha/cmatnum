#include "stdafx.h"
#include "fAxxeval7593.h"

inline int fAxxeval7593(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx226.data[0][0], 0, sizeof(bmats.Axx226.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1128, bmats.Axx1164, bmats.Axx1303, bmats.Axx1404, bmats.Axx1407, bmats.Axx145, bmats.Axx147, bmats.Axx1631, bmats.Axx1905, bmats.Axx2464, bmats.Axx266, bmats.Axx376, bmats.Axx535, bmats.Axx911, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx226, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
