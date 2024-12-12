#include "stdafx.h"
#include "fAxxeval5309.h"

inline int fAxxeval5309(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx834.data[0][0], 0, sizeof(bmats.Axx834.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_9_22, bmats.Axx1677, bmats.Axx2133, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx834, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
