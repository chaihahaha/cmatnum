#include "stdafx.h"
#include "fAxxeval8372.h"

inline int fAxxeval8372(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1368.data[0][0], 0, sizeof(bmats.Axx1368.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1220, bmats.Axx1288, bmats.Axx1532, bmats.Axx1545, bmats.Axx1595, bmats.Axx1730, bmats.Axx1875, bmats.Axx2824, bmats.Axx3179, bmats.Axx3290, bmats.Axx435, bmats.Axx466, bmats.Axx578, bmats.Axx832, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1368, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}