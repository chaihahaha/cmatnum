#include "stdafx.h"
#include "fAxxeval8483.h"

inline int fAxxeval8483(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3060.data[0][0], 0, sizeof(bmats.Axx3060.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_23_19, bmats.Axx1486, bmats.Axx1513, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx3060, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}