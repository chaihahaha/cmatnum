#include "stdafx.h"
#include "fAxxeval5474.h"

inline int fAxxeval5474(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx568.data[0][0], 0, sizeof(bmats.Axx568.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_7_18, bmats.Axx1763, bmats.Axx3288, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx568, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}