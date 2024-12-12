#include "stdafx.h"
#include "fAxxeval4495.h"

inline int fAxxeval4495(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx440.data[0][0], 0, sizeof(bmats.Axx440.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_16_10, bmats.Axx1874, bmats.Axx502, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx440, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
