#include "stdafx.h"
#include "fAxxeval7986.h"

inline int fAxxeval7986(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2871.data[0][0], 0, sizeof(bmats.Axx2871.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_25_21, bmats.Axx1774, bmats.Axx2201, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx2871, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
