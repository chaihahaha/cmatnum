#include "stdafx.h"
#include "fAxxeval5213.h"

inline int fAxxeval5213(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1703.data[0][0], 0, sizeof(bmats.Axx1703.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_10_21, bmats.Axx2128, bmats.Axx2141, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx1703, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
