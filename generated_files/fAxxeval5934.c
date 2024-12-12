#include "stdafx.h"
#include "fAxxeval5934.h"

inline int fAxxeval5934(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1503.data[0][0], 0, sizeof(bmats.Axx1503.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_11_24, bmats.Axx2091, bmats.Axx3161, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx1503, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
