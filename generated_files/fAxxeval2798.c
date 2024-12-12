#include "stdafx.h"
#include "fAxxeval2798.h"

inline int fAxxeval2798(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx804.data[0][0], 0, sizeof(bmats.Axx804.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_13_1, bmats.Axx1873, bmats.Axx489, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx804, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
