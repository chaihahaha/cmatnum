#include "stdafx.h"
#include "fAxxeval3429.h"

inline int fAxxeval3429(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2368.data[0][0], 0, sizeof(bmats.Axx2368.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_21_16, bmats.Axx2336, bmats.Axx2367, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx2368, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
