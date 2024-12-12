#include "stdafx.h"
#include "fAxxeval3003.h"

inline int fAxxeval3003(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx741.data[0][0], 0, sizeof(bmats.Axx741.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_11_11, bmats.Axx1912, bmats.Axx630, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx741, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
