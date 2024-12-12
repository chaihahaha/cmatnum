#include "stdafx.h"
#include "fAxxeval7799.h"

inline int fAxxeval7799(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2450.data[0][0], 0, sizeof(bmats.Axx2450.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_24_30, bmats.Axx1444, bmats.Axx379, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx2450, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
