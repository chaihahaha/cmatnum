#include "stdafx.h"
#include "fAxxeval5652.h"

inline int fAxxeval5652(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx414.data[0][0], 0, sizeof(bmats.Axx414.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx1670, bmats.Axx2404, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx414, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}