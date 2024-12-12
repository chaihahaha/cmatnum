#include "stdafx.h"
#include "fAxxeval5503.h"

inline int fAxxeval5503(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2208.data[0][0], 0, sizeof(bmats.Axx2208.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_7_27, bmats.Axx1603, bmats.Axx762, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx2208, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
