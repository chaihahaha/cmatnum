#include "stdafx.h"
#include "fAxxeval6988.h"

inline int fAxxeval6988(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1860.data[0][0], 0, sizeof(bmats.Axx1860.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1176, bmats.Axx1177, bmats.Axx699, };
    double A_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1860, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
