#include "stdafx.h"
#include "fAxxeval4646.h"

inline int fAxxeval4646(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3361.data[0][0], 0, sizeof(bmats.Axx3361.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx1384, bmats.Axx3358, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx3361, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
