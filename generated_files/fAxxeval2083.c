#include "stdafx.h"
#include "fAxxeval2083.h"

inline int fAxxeval2083(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1816.data[0][0], 0, sizeof(bmats.Axx1816.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx1801, bmats.Axx1815, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx1816, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
