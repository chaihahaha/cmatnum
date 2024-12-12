#include "stdafx.h"
#include "fAxxeval8420.h"

inline int fAxxeval8420(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx889.data[0][0], 0, sizeof(bmats.Axx889.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1242, bmats.Axx1510, bmats.Axx1718, bmats.Axx1861, bmats.Axx204, bmats.Axx2047, bmats.Axx2220, bmats.Axx2883, bmats.Axx297, bmats.Axx3043, bmats.Axx3126, bmats.Axx3237, bmats.Axx709, bmats.Axx778, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx889, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
