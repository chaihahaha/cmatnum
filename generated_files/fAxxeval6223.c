#include "stdafx.h"
#include "fAxxeval6223.h"

inline int fAxxeval6223(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1925.data[0][0], 0, sizeof(bmats.Axx1925.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx1505, bmats.Axx1603, bmats.Axx1654, bmats.Axx1673, bmats.Axx1777, bmats.Axx1801, bmats.Axx1966, bmats.Axx1982, bmats.Axx2018, bmats.Axx2087, bmats.Axx2104, bmats.Axx2343, bmats.Axx2973, bmats.Axx762, bmats.Axx851, bmats.Axx945, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1925, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
