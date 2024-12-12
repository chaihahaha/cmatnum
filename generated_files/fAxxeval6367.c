#include "stdafx.h"
#include "fAxxeval6367.h"

inline int fAxxeval6367(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1581.data[0][0], 0, sizeof(bmats.Axx1581.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1637, bmats.Axx3084, bmats.Axx562, bmats.Axx563, bmats.Axx744, bmats.Axx745, bmats.Axx821, bmats.Axx822, bmats.Axx859, bmats.Axx860, bmats.Axx861, bmats.Axx885, bmats.Axx906, bmats.Axx983, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1581, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
