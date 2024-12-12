#include "stdafx.h"
#include "fAxxeval1757.h"

inline int fAxxeval1757(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx206.data[0][0], 0, sizeof(bmats.Axx206.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_15_12, bmats.Axx1600, bmats.Axx1608, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx206, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
