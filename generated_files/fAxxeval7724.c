#include "stdafx.h"
#include "fAxxeval7724.h"

inline int fAxxeval7724(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2459.data[0][0], 0, sizeof(bmats.Axx2459.data[0][0])*BL*BL);
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.Axx1121, bmats.Axx1244, bmats.Axx1339, bmats.Axx1432, bmats.Axx1442, bmats.Axx1527, bmats.Axx2015, bmats.Axx203, bmats.Axx3024, bmats.Axx3140, bmats.Axx521, bmats.Axx579, };
    double A_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2459, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
