#include "stdafx.h"
#include "fAxxeval1755.h"

inline int fAxxeval1755(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1598.data[0][0], 0, sizeof(bmats.Axx1598.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_15_9, bmats.Axx1606, bmats.Axx208, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx1598, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
