#include "stdafx.h"
#include "fAxxeval7587.h"

inline int fAxxeval7587(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx338.data[0][0], 0, sizeof(bmats.Axx338.data[0][0])*BL*BL);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx116, bmats.Axx1164, bmats.Axx1303, bmats.Axx1404, bmats.Axx1407, bmats.Axx145, bmats.Axx147, bmats.Axx1631, bmats.Axx1905, bmats.Axx2464, bmats.Axx266, bmats.Axx376, bmats.Axx535, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx338, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
