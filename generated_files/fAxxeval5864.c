#include "stdafx.h"
#include "fAxxeval5864.h"

inline int fAxxeval5864(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2710.data[0][0], 0, sizeof(bmats.Axx2710.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx1603, bmats.Axx1637, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx2710, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
