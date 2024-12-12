#include "stdafx.h"
#include "fAxxeval4866.h"

inline int fAxxeval4866(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1904.data[0][0], 0, sizeof(bmats.Axx1904.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_5_23, bmats.Axx192, bmats.Axx993, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx1904, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
