#include "stdafx.h"
#include "fAxxeval3394.h"

inline int fAxxeval3394(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2340.data[0][0], 0, sizeof(bmats.Axx2340.data[0][0])*BL*BL);
    int n_A_mats = 1;
    double_cmat A_mats[1] = {bmats.A_21_13, };
    double A_coeffs[1] = {-1, };
    matlincomb_double_contiguous(bmats.Axx2340, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
