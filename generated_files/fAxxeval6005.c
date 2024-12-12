#include "stdafx.h"
#include "fAxxeval6005.h"

inline int fAxxeval6005(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1488.data[0][0], 0, sizeof(bmats.Axx1488.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_16_18, bmats.Axx1016, bmats.Axx411, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx1488, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
