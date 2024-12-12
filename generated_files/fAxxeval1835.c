#include "stdafx.h"
#include "fAxxeval1835.h"

inline int fAxxeval1835(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1689.data[0][0], 0, sizeof(bmats.Axx1689.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1684, bmats.Axx233, bmats.Axx236, bmats.Axx237, bmats.Axx242, bmats.Axx243, bmats.Axx249, bmats.Axx250, bmats.Axx257, bmats.Axx258, bmats.Axx261, bmats.Axx262, bmats.Axx297, bmats.Axx298, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1689, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
