#include "stdafx.h"
#include "fAxxeval5508.h"

inline int fAxxeval5508(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx945.data[0][0], 0, sizeof(bmats.Axx945.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_7_32, bmats.Axx1870, bmats.Axx3278, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx945, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}