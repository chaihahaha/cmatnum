#include "stdafx.h"
#include "fAxxeval5479.h"

inline int fAxxeval5479(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx586.data[0][0], 0, sizeof(bmats.Axx586.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_7_22, bmats.Axx1698, bmats.Axx1940, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx586, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
