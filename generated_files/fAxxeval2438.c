#include "stdafx.h"
#include "fAxxeval2438.h"

inline int fAxxeval2438(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1977.data[0][0], 0, sizeof(bmats.Axx1977.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_10_13, bmats.Axx1631, bmats.Axx1945, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx1977, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
