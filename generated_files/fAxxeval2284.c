#include "stdafx.h"
#include "fAxxeval2284.h"

inline int fAxxeval2284(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1916.data[0][0], 0, sizeof(bmats.Axx1916.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1887, bmats.Axx1911, bmats.Axx541, bmats.Axx542, bmats.Axx568, bmats.Axx569, bmats.Axx572, bmats.Axx573, bmats.Axx575, bmats.Axx576, bmats.Axx583, bmats.Axx584, bmats.Axx614, bmats.Axx615, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1916, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}