#include "stdafx.h"
#include "fAxxeval2069.h"

inline int fAxxeval2069(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1803.data[0][0], 0, sizeof(bmats.Axx1803.data[0][0])*BL*BL);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx1800, bmats.Axx466, bmats.Axx467, bmats.Axx468, bmats.Axx469, bmats.Axx470, bmats.Axx471, bmats.Axx472, bmats.Axx473, bmats.Axx474, bmats.Axx475, bmats.Axx476, bmats.Axx544, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1803, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}